```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, m, dp[10][MAX];
string s;

ll OPT(ll n, ll m){
    if(n + m < 10) return 1;
    ll &cur = dp[n][m];
    if(cur!=-1) return cur;
    return cur = (OPT(1, n+m-10) + OPT(0, n+m-10))%MOD;
}

void solve(){        
    cin>>s>>m; 
    ll r = 0;
    for(char c : s) r=(r+OPT(c-'0', m))%MOD; 
    cout<<r<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
