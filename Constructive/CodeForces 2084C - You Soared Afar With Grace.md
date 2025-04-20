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
ll n, a[MAX], b[MAX];
map<ll, ll> p;
vec<pair<ll, ll>> r;

void fun(int x, int y) {
    if(x==y) return;
    swap(a[x], a[y]);
	swap(p[a[x]], p[a[y]]);
	swap(b[x], b[y]);
	r.pb({x, y});
}

void solve(){        
    cin>>n; p.clear(), r.clear();
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) p[a[i]]=i;
    for(int i=0; i<n; ++i) cin>>b[i];
    ll idx=-1;
    for(int i=0; i<n; ++i) {
        if(a[i]==b[i]) {
            if(n%2==0 || idx>=0) {cout<<-1<<endl; return;}
            idx=i;
        }else if(b[p[b[i]]]!=a[i]) {cout<<-1<<endl; return;}
    }
    if(n&1) fun(idx, n/2);
    for(int i=0; i<n; ++i) fun(p[b[i]], n-i-1);
    cout<<r.size()<<endl;
    for(auto &[x, y] : r) cout<<x+1<<' '<<y+1<<endl;
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
