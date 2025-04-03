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
ll n;

ll power2(ll x) {
    ll i=log2(x);
    if((1LL<<i) == x) --i;
    while(x%(1LL<<i)) i--;
    return 1LL<<i;
}

void solve(){        
    cin>>n;
    vec<ll> rs; rs.pb(1);
    while(n>1) rs.pb(n), n-=power2(n);
    sort(ALL(rs), greater<ll>());
    cout<<rs.size()<<endl;
    for(auto &i : rs) cout<<i<<' '; cout<<endl;
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
