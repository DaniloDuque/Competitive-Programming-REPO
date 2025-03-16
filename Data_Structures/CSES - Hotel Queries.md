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
#define oper max
#define NEUT 0
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, m, fr[MAX], gr[MAX];
 
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
	    if(s+1==e){st[k]+=v;return;}
	    ll m=(s+e)>>1;
	    (p<m)? upd(2*k,s,m,p,v) : upd(2*k+1,m,e,p,v);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }
 
    ll query(ll k, ll s, ll e, ll i){
        if(st[k]<i) return -1;
	    if(s+1==e) return s; 
	    ll m=(s+e)>>1;
	    ll rs = query(2*k,s,m,i);
	    if(rs>-1) return rs;
	    return query(2*k+1,m,e,i);
    };
 
    void init(ll *a){init(1,0,n,a);}
    void upd(ll p, ll v){upd(1,0,n,p,v);}
    ll query(ll i){return query(1,0,n,i);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);
 
void solve(){        
    cin>>n>>m; 
    for(int i=0; i<n; ++i) cin>>fr[i];
    for(int i=0; i<m; ++i) cin>>gr[i];
    STree tree(n); tree.init(fr);
    for(int i=0; i<m; ++i) {
        ll idx = tree.query(gr[i]);
        cout<<idx+1<<' ';
        if(idx>=0) tree.upd(idx, -gr[i]);
    }cout<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
