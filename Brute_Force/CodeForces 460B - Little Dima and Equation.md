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
const int MAX = 1e9;
ll a, b, c;

ll s(ll x) {
    ll r = 0;
    while(x) r+=x%10, x/=10;
    return r;
}

ll exp(ll b, ll e) {
    if(!e) return 1;
    if(e&1) return b*exp(b*b, e>>1);
    return exp(b*b, e>>1);
}

void solve(){        
    cin>>a>>b>>c;
    vec<ll> r;
    for(int i=1; i<82; ++i) {
        ll cur = b*exp(i, a)+c;
        if(cur < MAX && s(cur)==i) r.pb(cur);
    }
    cout<<r.size()<<endl;
    for(auto &i : r) cout<<i<<' ';
    if(r.size()) cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
