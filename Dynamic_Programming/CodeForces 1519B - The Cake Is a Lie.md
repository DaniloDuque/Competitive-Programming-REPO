```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;
vector<vector<int>> dp;


bool possibleCost(int i, int j, int cost = 0){

    if(i == n && j == m) return cost == k;

    if(i > n || j > m) return false;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(possibleCost(i+1, j, cost + j), possibleCost(i, j+1, cost + i));

}


int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n>>m>>k;
        dp.assign(n+1, vector<int>(m+1, -1));
        cout<<(possibleCost(1, 1)? "YES\n": "NO\n");

    }return 0;

}
