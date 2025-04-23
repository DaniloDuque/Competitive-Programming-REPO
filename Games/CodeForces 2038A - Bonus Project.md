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
ll n, k, a[MAX], b[MAX];

vec<ll> solve(){        
    cin>>n>>k;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    vec<ll> rs, def(n, 0);
    for(int i=n-1; i>0; --i) {
        ll cur = a[i]/b[i];
        rs.pb(min(k, cur));
        k-=min(k, cur);
    }rs.pb(k);
    reverse(ALL(rs));
    if(k*b[0] > a[0]) return def;
    return rs;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        for(auto i : solve()) cout<<i<<' '; cout<<endl;
    }return 0;
}
