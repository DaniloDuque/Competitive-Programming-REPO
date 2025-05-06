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
#define pll pair<ll,ll>
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, k;

pll luck(ll l, ll r) {
    ll s = r-l+1, m=(l+r)>>1;
    if(s<k) return {0, 0};
    auto [x, c] = luck(m+1, r);
    if(s&1) return {2*x - c*m + c*(l-1) + m, 2*c+1};
    return {2*x - c*m + c*(l-1), 2*c};
}

void solve(){        
    cin>>n>>k;
    cout<<luck(1, n).fst<<endl;
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
