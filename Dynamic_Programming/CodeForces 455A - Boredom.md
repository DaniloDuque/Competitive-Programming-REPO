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
const int MAX = 1e5+20, MOD = 1e9+7;
ll n, x, mx;
map<ll, ll> mp;
vec<ll> dp;

ll BT(ll i) {
    if(i>mx) return 0;
    ll &cur = dp[i];
    if(cur != -1) return cur;
    return cur = max(i*mp[i]+BT(i+2), BT(i+1));
}

void solve(){        
    cin>>n; dp.assign(MAX, -1);
    for(int i=0; i<n; ++i) cin>>x, mx=max(mx, x), mp[x]++;
    cout<<BT(0)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
