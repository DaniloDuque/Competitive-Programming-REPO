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
#define ll long long
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, x;
vec<ll> arr, dp;

void solve(){        
    cin>>n>>x; arr.assign(n+1, 0);
    for(int i=1; i<=n; ++i) cin>>arr[i];
    partial_sum(ALL(arr), arr.begin());
    dp.assign(n+2, 0);
    for(int i=n-1; i>=0; --i) {
        int j = upper_bound(ALL(arr), x+arr[i])-arr.begin();
        dp[i] = dp[j]+j-i-1;
    }cout<<accumulate(ALL(dp), 0LL)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
