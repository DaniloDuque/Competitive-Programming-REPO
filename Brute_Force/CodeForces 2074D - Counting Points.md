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
ll n, m;
vec<pair<ll, ll>> arr;
map<ll, ll> mp;

void solve(){        
    cin>>n>>m; arr.resize(n); mp.clear();
    for(auto &[x, _] : arr) cin>>x;
    for(auto &[_, y] : arr) cin>>y;
    for(auto &[xi, r] : arr)
        for(ll x=xi-r; x<=xi+r; ++x) 
            mp[x]=max(mp[x], 1 + 2*(ll)sqrt(r*r - (xi-x)*(xi-x)));
    ll r = 0;
    for(auto &[_, v] : mp) r+=v;
    cout<<r<<endl;
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
