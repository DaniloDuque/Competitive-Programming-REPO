```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long long
#define oo 1000000000LL


int n, d_i, c_i, f_i, u_i, sumDel = 0;
vector<int> delegates, bribes;
vector<vector<int>> dp;




int minBribery(int i, int winned){

    if(winned >= sumDel) return 0;

    if(i == n) return oo;

    if(dp[i][winned] != -1) return dp[i][winned];

    return dp[i][winned] = min(minBribery(i+1, winned), bribes[i] + minBribery(i+1, winned + delegates[i]));

}



signed main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    dp.assign(n, vector<int>(2016, -1));

    for(int i = 0; i<n; i++){

        cin>>d_i>>c_i>>f_i>>u_i;
        delegates.push_back(d_i);
        bribes.push_back((2 + f_i + u_i - c_i)>>1);
        bribes[i] = max(0LL, (bribes[i] > u_i)? oo: bribes[i]);
        sumDel += d_i;

    }sumDel = (sumDel>>1)+1;
    
    int rslt = minBribery(0, 0);
    (rslt >= oo)? cout<<"impossible\n": cout<<rslt<<'\n'; 
    return 0;

}
