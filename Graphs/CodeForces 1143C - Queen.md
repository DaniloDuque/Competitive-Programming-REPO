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
const int MAX = 1e5+20, MOD = 1e9+7;
ll n, x, y, c[MAX], arr[MAX], ft[MAX];
vec<vec<ll>> G;
vec<ll> rs;

void solve(){        
    cin>>n; G.resize(n+1);
    for(int i=1; i<=n; ++i) {
        cin>>x>>y;
        ft[i]=x; c[i]=y;
        if (x >= 1 && x <= n) G[x].pb(i);  
    }
    for(int i=1; i<=n; ++i) {
        arr[i]=c[i];
        for(auto &k : G[i]) arr[i]&=c[k];
        if(ft[i] > 0 && arr[i]) rs.pb(i);
    }
    if(rs.empty()) {cout<<-1<<endl; return;}
    for(auto &i : rs) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
