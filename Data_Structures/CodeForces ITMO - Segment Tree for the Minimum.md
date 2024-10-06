```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
#define oper min
#define NEUT 1e9
const int MAX = 2e5+20;
int t=1, n, m, arr[MAX], x, y, op;

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
    cin>>n>>m;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    STree st(n); st.init(arr);
    while(m--){
        cin>>op>>x>>y;
        if(op==1) st.upd(x, y);
        else cout<<st.query(x, y)<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
