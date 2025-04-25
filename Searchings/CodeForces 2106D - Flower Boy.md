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
ll n, m, a[MAX], b[MAX];

bool check(ll k) {
    vec<vec<ll>> dp(n+1, vec<ll>(2, 0));
    dp[n][1]=(b[0]<=k);
    for(int i=n-1; i>=0; --i) {
        dp[i][0]=dp[i+1][0]+(a[i]>=b[dp[i+1][0]]);
        dp[i][1]=dp[i+1][1]+(a[i]>=b[dp[i+1][1]]);
        if(dp[i][0]<m && b[dp[i][0]] <= k) dp[i][1]=max(dp[i][1], dp[i][0]+1);
        if(dp[i][0]>=m || dp[i][1] >= m) return 1;
    }return 0;
}

ll solve(){        
    cin>>n>>m;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<m; ++i) cin>>b[i];
    reverse(b, b+m);
    ll l=0, r=MOD;
    while(l!=r) {
        ll mid = (l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l>1e9) return -1;
    return l;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
