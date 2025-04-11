```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, m;
vec<string> arr;
vec<vec<ll>> dp;

void solve(){        
    cin>>n>>m; arr.resize(n);
    dp.assign(n+1, vec<ll>(m+1, 0));
    for(auto &i : arr) cin>>i;
    ll r = 0;
    for(int i=0; i<m; ++i) r+=(arr[n-1][i]=='*'), dp[n-1][i]=arr[n-1][i]=='*';
    for(int i=n-2; i>=0; --i) {
        for(int j=0; j<m; ++j) {
            if(arr[i][j]=='.') continue;
            if(!j || j==m-1) {r++, dp[i][j]=1; continue;}
            ll cur = 1+min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
            r+=cur, dp[i][j]=cur;
        }
    }cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
