```cpp
#include <bits/stdc++.h>
using namespace std;



#define int long long
#define oo 30001
int n, arr[101], dp[101][oo], q, x;





void coinChange(){

    for(int i = 0; i<=n; ++i) dp[i][0] = 1;
    for(int i = n-1; i>=0; --i)
        for(int j = 1; j<oo; ++j){
            dp[i][j] = dp[i+1][j];
            if(j >= arr[i]) dp[i][j] += dp[i][j-arr[i]];
        }

}



void route(int i, int j) {

    if (j <= 0) return;
    if(dp[i+1][j]) return route(i+1, j);
    cout<<i+1<<' ';
    return route(i, j-arr[i]);

}




signed main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i = 0; i<n; i++) cin>>arr[i];
    coinChange();
    cin>>q;

    while(q--){

        cin>>x;
        if(dp[0][x] > 1) cout<<"Ambiguous";
        else if(dp[0][x]) route(0, x);
        else cout<<"Impossible";
        cout<<'\n';

    }return 0;

}
