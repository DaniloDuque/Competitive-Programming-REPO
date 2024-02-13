```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo (1<<29|1<<28)
#define vi vector<int>
int f, s, g, u, d;
vi dp;
priority_queue<int, vi, function<bool(int, int)>> pq([](int a, int b) -> bool {
    return dp[a] < dp[b];
});




int main(){

    cin>>f>>s>>g>>u>>d;
    dp.assign(f+1, oo);

    dp[s] = 0;
    pq.push(s);

    while(!pq.empty()){

        int curr = pq.top(); pq.pop();
        if(curr == g) break;

        if(curr + u <= f && dp[curr] + 1 < dp[curr+u]){
            dp[curr+u] = 1 + dp[curr];
            pq.push(curr+u);

        }if(curr-d >= 0 && dp[curr] + 1 < dp[curr-d]){
            dp[curr-d] = 1 + dp[curr];
            pq.push(curr-d);
        }

    }(dp[g] >= oo)? cout<<"use the stairs\n": cout<<dp[g]<<'\n';
    return 0;

}
