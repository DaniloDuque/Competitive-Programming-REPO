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
ll n, m, dp[MAX];
vec<ll> arr;

void solve(){        
    cin>>n>>m; arr.resize(m);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    ll rs=0;
    for(ll i=1; i<n; ++i) dp[i] = m-(lower_bound(ALL(arr), n-i)-arr.begin());
    for(int i=n-arr.back(); i<=arr.back(); ++i) rs+=(max(dp[i], dp[n-i])-1)*min(dp[i], dp[n-i]);
    cout<<rs<<endl;
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
