```cpp
#include <bits/stdc++.h>
using namespace std;



#define oo (1<<29|1<<28)
#define duo pair<int, int>
#define f first
#define s second
int n, m, v1, v2, w, dists[1001], dp[1001];
vector<vector<duo>> G;




void bfs(){

    queue<int> Q; Q.push(1);
    dists[1] = 0;

    while(!Q.empty()){

        int curr = Q.front(); Q.pop();

        for(duo &nxt: G[curr])

            if(dists[nxt.s] > dists[curr] + nxt.f){

                dists[nxt.s] = dists[curr] + nxt.f;
                Q.push(nxt.s);

            }

    }


}



int solve(int i){

    if(i == 1) return 1;

    if(dp[i] != -1) return dp[i];

    dp[i] = 0;

    for(duo &nxt: G[i])

        if(dists[nxt.s] < dists[i]) dp[i] += solve(nxt.s);

    return dp[i];

}




int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n>>m && n){

        G.assign(n, {});
        fill(dists, dists+n, oo);
        fill(dp, dp+n, -1);
        while(m--){

            cin>>v1>>v2>>w;
            G[--v1].emplace_back(w, --v2);
            G[v2].emplace_back(w, v1);


        }bfs();
        cout<<solve(0)<<'\n';


    }return 0;

}
