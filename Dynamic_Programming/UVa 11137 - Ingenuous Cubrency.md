```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long


int dp[22][10001];
int n;



int cub(int i){
    return i*i*i;
}


int coinChange(){

    for(int i = 20; i>=0; i--)
        for(int j = 1; j<=n; j++){
            if(j >= cub(i+1)) dp[i][j] = dp[i][j - cub(i+1)];
            dp[i][j] += dp[i+1][j];
        }

    return dp[0][n];

}


signed main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    for(int i = 0; i<21; i++) dp[i][0] = 1;
    while(cin>>n) cout<<coinChange()<<'\n';
    return 0;

}
