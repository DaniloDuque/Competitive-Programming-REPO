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
ll n, m1, m2, u, v;
set<pair<ll, ll>> sF, sG;

struct UnionFind{
    vector<int> uf;
    void init(int n){uf.assign(n, -1);}
    int Find(int i){return (uf[i]==-1)? i : uf[i] = Find(uf[i]);}
    bool Union(int i, int j){
        bool e = Find(i)==Find(j);
        if(!e) uf[Find(i)] = Find(j);
        return e;
    }
};

void solve(){        
    cin>>n>>m1>>m2;
    sF.clear(); sG.clear();
    while(m1--) {
        cin>>u>>v;
        sF.insert({--u, --v});
    } 
    while(m2--) {
        cin>>u>>v;
        sG.insert({--u, --v});
    }
    ll r = 0;
    UnionFind uF, uG;
    uF.init(n), uG.init(n);
    for(auto &[x, y] : sG) uG.Union(x, y);
    vec<pair<ll, ll>> e;
    for(auto &[x, y] : sF) if(uG.Find(x)!=uG.Find(y)) r++, e.pb({x, y});
    for(auto &i : e) sF.erase(i);
    for(auto &[x, y] : sF) uF.Union(x, y);
    for(auto &[x, y] : sG) if(uF.Find(x)!=uF.Find(y)) r++, uF.Union(x, y);
    cout<<r<<endl;
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
