```cpp
#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define oo (1LL<<60|1LL<<59)


ll n, w, MAX = 0;
vector<ll> values, weights;
vector<vector<ll>> dp;



ll minWeight(ll i, ll item){

    if(i < 0) return oo;

    if(item == n) return (i)? oo: 0;

    if(dp[i][item] != -1) return dp[i][item];

    return dp[i][item] = min(minWeight(i, item + 1), weights[item] + minWeight(i - values[item], item + 1));

}


ll findMAX(){

    for(ll i = MAX; i>=0; --i) 
    
        if(minWeight(i, 0) <= w) return i;

    return 0;
    
}


int main(){

    ios::sync_with_stdio(false);
    cin>>n>>w;
    values.assign(n, 0); weights.assign(n, 0);

    for(ll i = 0; i<n; i++){
        
        cin>>weights[i]>>values[i];
        MAX += values[i];

    }

    dp.assign(MAX+1, vector<ll>(n+1, -1));
    cout<<findMAX()<<'\n';
    return 0;

}
