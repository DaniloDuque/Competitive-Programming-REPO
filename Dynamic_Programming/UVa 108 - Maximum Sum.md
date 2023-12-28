```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int n;


int solve(){

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

    int max = INT_MIN;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            for(int x = i; x<=n; x++)
                for(int y = j; y<=n; y++)
                    max = std::max(max, dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1]);
                
    return max;

}



int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            cin>>dp[i][j];
    cout<<solve()<<'\n';

}
