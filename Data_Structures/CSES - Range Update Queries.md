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
ll n, arr[MAX], ins, x, y, z, q;
 
struct STree { 
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		lazy[k]=0;  
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; 
	}
	void push(ll k, ll s, ll e){
		if(!lazy[k])return; 
		st[k]+=(e-s)*lazy[k]; 
		if(s+1<e){ 
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}lazy[k]=0;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; 
			push(k,s,e);return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; 
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return 0; 
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
 
void solve(){        
    cin>>n>>q;
    for(int i=0; i<n; ++i) cin>>arr[i];
    STree tree(n); tree.init(arr);
    while(q--) {
        cin>>ins;
        if(ins == 1) {
            cin>>x>>y>>z;
            tree.upd(x-1, y, z);
        }else {
            cin>>x;
            cout<<tree.query(x-1, x)<<endl;
        }
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
