```cpp
#include <bits/stdc++.h>
using namespace std;


int n, w;
#define ll long long

vector<int> values, weights;
vector<vector<ll>> dp;


ll Knapsack(int i, int leftSpace){

    if(leftSpace < 0) return LLONG_MIN;
    
    if(i < 0 || !leftSpace) return 0;

    if(dp[i][leftSpace] != LLONG_MIN) return dp[i][leftSpace];

    return dp[i][leftSpace] = max(values[i] + Knapsack(i-1, leftSpace - weights[i]), Knapsack(i-1, leftSpace));
}


int main(){

    ios::sync_with_stdio(false);
    cin>>n>>w;
    values.assign(n, 0); weights.assign(n, 0);
    dp.assign(n+1, vector<ll>(w+1, LLONG_MIN));

    for(int i = 0; i<n; i++){

        cin>>weights[i];
        cin>>values[i];

    }cout<<Knapsack(n-1, w)<<'\n';
    return 0;

}
