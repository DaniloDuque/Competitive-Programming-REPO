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
#define ll long long
#define NEUT {INT_MAX, 1}
#define pi pair<int, int>
const int MAX = 1e5+20;
int t=1, n, m, ins, x, y, arr[MAX];

pi oper(pi a, pi b){
    int min = std::min(a.fst, b.fst);
    return {min, (min==a.fst && min==b.fst)? a.snd+b.snd : (min==a.fst)? a.snd : b.snd}; 
}

//pair<min of segment, number of mins in the segment>
struct STree { 
    vec<pi> st; int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void init(int k, int s, int e, int *a){
	    if(s+1==e){st[k]={a[s], 1} ;return;}
	    int m=(s+e)>>1;
	    init(2*k,s,m,a);init(2*k+1,m,e,a);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }

    void upd(int k, int s, int e, int p, int v){
	    if(s+1==e){st[k]={v, 1};return;}
	    int m=(s+e)>>1;
	    (p<m)? upd(2*k,s,m,p,v) : upd(2*k+1,m,e,p,v);
	    st[k]=oper(st[2*k],st[2*k+1]);
    }

    pi query(int k, int s, int e, int a, int b){
	    if(s>=b||e<=a)return NEUT;
	    if(s>=a&&e<=b)return st[k];
	    int m=(s+e)>>1;
	    return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }

    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    pi query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    STree st(n); st.init(arr);
    while(m--){
        cin>>ins>>x>>y;
        if(ins==1) st.upd(x, y);
        else{
            auto q = st.query(x, y);
            cout<<q.fst<<' '<<q.snd<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
