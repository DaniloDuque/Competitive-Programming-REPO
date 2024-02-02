```cpp
#include <bits/stdc++.h>
using namespace std;


int n, c, prices[200001];
vector<vector<int>> dp;



int maxProfit(int i, bool bought = false){

    if(i == n) return 0;

    if(dp[bought][i] != -1) return dp[bought][i];

    if(bought) return dp[bought][i] = max(maxProfit(i+1, 1), prices[i] + maxProfit(i+1, 0));

    return dp[bought][i] = max(maxProfit(i+1, 0), maxProfit(i+1, 1) - c - prices[i]);
    
}



int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    while(cin>>n>>c){

        dp.assign(2, vector<int>(n, -1));
        for(int i = 0; i<n; i++)cin>>prices[i];
        cout<<maxProfit(0)<<'\n';

    }return 0;

}
