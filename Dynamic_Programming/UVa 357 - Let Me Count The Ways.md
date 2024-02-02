```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long


short coins[5] = {1, 5, 10, 25, 50};

int n, dp[6][30001];


void coinChange(){

    for(int i = 4; i>=0; i--)
        for(int j = 1; j<=n; j++){
            if(j >= coins[i]) dp[i][j] = dp[i][j - coins[i]];
            dp[i][j] += dp[i+1][j];
        }

    (dp[0][n] == 1)? cout<<"There is only 1 way to produce "<<n<<" cents change.\n": 
    cout<<"There are "<<dp[0][n]<<" ways to produce "<<n<<" cents change.\n";

}


signed main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    for(int i = 0; i<5; i++) dp[i][0] = 1;  
    while(cin>>n) coinChange();
    return 0;

}
