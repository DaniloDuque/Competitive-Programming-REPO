```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n, arr[MAX], rs[MAX], vis[MAX], u, v;
vec<ll> G[MAX];

void threat(int v = 1, ll p_v = 0, ll pp_v = 0) {
    if(vis[v]) return;
    vis[v] = 1;
    rs[v] = arr[v] + max(0LL, rs[pp_v]-arr[p_v]);
    for(auto &n_v : G[v]) threat(n_v, v, p_v);
}

void solve(){        
    cin>>n; 
    for(int i=1; i<=n; ++i) {
        cin>>arr[i];
        rs[i]=vis[i]=0;
        G[i]={};
    }
    for(int i=1; i<n; ++i) {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    threat();
    for(int i=1; i<=n; ++i) cout<<rs[i]<<' ';
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
