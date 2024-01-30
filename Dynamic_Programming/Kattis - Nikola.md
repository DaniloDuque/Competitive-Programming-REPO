```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo (1<<27|1<<26)
int n, fee[1001];
vector<vector<int>> dp;


int minCost(int i, int lastJump){

    if(i >= n || i < 0) return oo;

    if(i == n-1) return fee[i];

    if(dp[i][lastJump] != oo) return dp[i][lastJump];

    return dp[i][lastJump] = fee[i] + min(minCost(i-lastJump, lastJump), minCost(i+lastJump+1, lastJump+1));

}


int main() {

    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>fee[i];
    dp.assign(n, vector<int>(n, oo));
    cout<<minCost(1, 1)<<'\n';
    return 0;

}
