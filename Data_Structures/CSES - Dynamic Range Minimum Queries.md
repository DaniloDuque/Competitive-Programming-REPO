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
#define oper min
#define NEUT MOD
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n, q, ins, x, y, arr[MAX];
 
struct STree { 
    vector<ll> st;ll n;
    STree(ll n): st(4*n+5,NEUT), n(n) {}
    void init(ll k, ll s, ll e, ll *a){
	    if(s+1==e){st[k]=a[s];return;}
	    ll m=(s+e)>>1;
	    init(2*k,s,m,a);init(2*k+1,m,e,a);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }
 
    void upd(ll k, ll s, ll e, ll p, ll v){
	    if(s+1==e){st[k]=v;return;}
	    ll m=(s+e)>>1;
	    (p<m)? upd(2*k,s,m,p,v) : upd(2*k+1,m,e,p,v);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }
 
    ll query(ll k, ll s, ll e, ll a, ll b){
	    if(s>=b||e<=a)return NEUT;
	    if(s>=a&&e<=b)return st[k];
	    ll m=(s+e)>>1;
	    return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
 
    void init(ll *a){init(1,0,n,a);}
    void upd(ll p, ll v){upd(1,0,n,p,v);}
    ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);
 
void solve(){        
    cin>>n>>q;
    for(ll i=0; i<n; ++i) cin>>arr[i];
    STree tree(n); tree.init(arr);
    while(q--) {
        cin>>ins>>x>>y;
        if(ins==1) tree.upd(x-1, y);
        else cout<<tree.query(x-1, y)<<endl;
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }return 0;
}
