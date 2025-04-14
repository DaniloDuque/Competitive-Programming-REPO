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
ll n, m, k;

void case1(){
    vec<ll> v;
    for(int i=1; i<=k; ++i) v.pb(i);
    for(int i=1, j=0; i<=(n*m); ++i, j=(j+1)%k) {
        cout<<v[j]<<' ';
        if(i%m == 0) cout<<endl; 
    }
}

vec<ll> shift(vec<ll> &v) {
    vec<ll> cur; cur.pb(v.back());
    for(int i=0; i<v.size()-1; ++i) cur.pb(v[i]);
    return cur;
}

void case2(ll n, ll m, ll t){
    vec<vec<ll>> mat(1, vec<ll>(m, 0));
    ll cur = 0;
    for(auto &i : mat[0]) i=(cur%k)+1, cur=(cur+1)%k; 
    for(int i=1; i<n; ++i) mat.pb(shift(mat[i-1]));
    if(t) {
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) cout<<mat[j][i]<<' '; cout<<endl;
        } return;
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) cout<<mat[i][j]<<' '; cout<<endl;
    }
}

void solve(){        
    cin>>n>>m>>k;
    if((n%k) && (m%k)) case1();
    else if(n%k) case2(n, m, 0);
    else case2(m, n, 1);
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
