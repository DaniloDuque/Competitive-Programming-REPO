```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define NEUT 1
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, mod, arr[MAX];
string s;

int oper(int a, int b){return (a*b)%mod;}

struct STree { 
    vector<int> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void init(int k, int s, int e, int *a){
	    if(s+1==e){st[k]=a[s];return;}
	    int m=(s+e)>>1;
	    init(2*k,s,m,a);init(2*k+1,m,e,a);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }

    void upd(int k, int s, int e, int p, int v){
	    if(s+1==e){st[k]=v;return;}
	    int m=(s+e)>>1;
	    (p<m)? upd(2*k,s,m,p,v) : upd(2*k+1,m,e,p,v);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }

    int query(int k, int s, int e, int a, int b){
	    if(s>=b||e<=a)return NEUT;
	    if(s>=a&&e<=b)return st[k];
	    int m=(s+e)>>1;
	    return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }

    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

void solve(){        
    cin>>n>>mod;
    for(int i = 0; i<n; ++i) cin>>arr[i], arr[i]%=mod;
    STree st(n); st.init(arr); 
    cin>>s;
    for(int k = 0, i = 0, j = n; k<n; ++k){
        cout<<st.query(i, j)<<' ';
        if(s[k]=='L') ++i;
        else --j;
    }cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
