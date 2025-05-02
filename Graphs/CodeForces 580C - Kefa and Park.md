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
ll n, m, u, v;
vec<ll> c;
vec<vec<ll>> G;

ll dfs(int i, int ct, int l) {
    ct=(ct+1)*c[i];
    if(ct>m) return 0;
    if(G[i].size()==1 && i) return 1;
    ll r = 0;
    for(auto &v : G[i]) if(v!=l) r+=dfs(v, ct, i);
    return r;
}

void solve(){        
    cin>>n>>m; c.resize(n);
    G.assign(n+1, {});
    for(auto &i : c) cin>>i;
    for(int i=1; i<n; ++i) {
        cin>>u>>v;
        G[--u].pb(--v);
        G[v].pb(u);
    }cout<<dfs(0, 0, -1)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
