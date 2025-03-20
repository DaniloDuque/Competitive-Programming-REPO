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
const ll MAX = 2e5+20, MOD = 1e9+7, MIN = -(1LL<<31);
 
ll n, p;
pair<ll, ll> arr[MAX];
 
struct LazySTree { 
    vector<pair<ll, ll>> st; vec<ll> lazy; vec<int> removed; ll n;
    LazySTree(ll n): st(4*n+5, {0, 0}), lazy(4*n+5, 0), removed(4*n+5, 0), n(n) {}
    void init(ll k, ll s, ll e, pair<ll, ll> *a) {
        if(s+1 == e) {st[k] = a[s]; return;}
        ll m=(s+e)>>1;
        init(2*k, s, m, a);
        init(2*k+1, m, e, a);
        st[k]=max(st[2*k], st[2*k+1]); 
    }
    
    void push(ll k, ll s, ll e) {
        st[k].fst += lazy[k];
        if(s+1 < e) { 
            lazy[2*k] += lazy[k];   
            lazy[2*k+1] += lazy[k]; 
        }lazy[k] = 0; 
        if(removed[k] && s+1 < e) {
            removed[2*k] |= (st[k].fst == MIN);
            removed[2*k+1] |= (st[k].fst == MIN);
        }
    }
    
    void remove(ll k, ll s, ll e, ll pos) {
        push(k, s, e);
        if(s>pos || e<=pos) return;
        if(s==pos && s+1==e) {st[k].fst=MIN, removed[k]=1; return;}
        ll m=(s+e)/2;
        remove(2*k,s,m,pos);
        remove(2*k+1,m,e,pos);
        st[k] = max(st[2*k], st[2*k+1]);
        removed[k]=removed[2*k]&removed[2*k+1];
    }
    
    void upd(ll k, ll s, ll e, ll a, ll b, ll v) {
        push(k, s, e); 
        if(s>=b || e<=a) return; 
        if(s>=a && e<=b) {lazy[k]+=v; push(k, s, e); return;}
        ll m = (s+e)>>1;
        upd(2*k, s, m, a, b, v);   
        upd(2*k+1, m, e, a, b, v); 
        st[k] = max(st[2*k], st[2*k+1]); 
    }   
    
    pair<ll, ll> query(ll k, ll s, ll e, ll v) {
        push(k, s, e);
        if(st[k].fst < v || removed[k]) return {MIN, MIN};
        if(s+1 == e) return {st[k].snd, s};
        ll m = (s+e)>>1;
        push(2*k, s, m);
        push(2*k+1, m, e);
        if(st[2*k].fst >= v && !removed[2*k]) return query(2*k, s, m, v);
        return query(2*k+1, m, e, v);
    }
    
    void init(pair<ll, ll> *a) { init(1, 0, n, a); }
    void remove(ll pos) { remove(1, 0, n, pos); }
    void upd(ll a, ll b, ll v) { upd(1, 0, n, a, b, v); }
    pair<ll, ll> query(ll v) { return query(1, 0, n, v); }
}; 
 
void solve() {        
    cin>>n;
    for(int i=0; i<n; ++i) cin>>arr[i].snd, arr[i].fst=i;
    LazySTree tree(n); tree.init(arr);
    for(int i=0; i<n; ++i) {
        cin>>p;
        auto [v, idx] = tree.query(p-1);
        cout<<v<<' ';
        tree.remove(idx);
        tree.upd(idx, n, -1);
    }cout<<endl;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
