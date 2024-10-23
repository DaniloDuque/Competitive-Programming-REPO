```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 4e5+20, MOD = 1e9+7;
ll t=1, n, a[MAX], b[MAX], dp[MAX];
priority_queue<pair<ll, ll>> pq;

void solve(){        
    cin>>n; MSET(dp, MOD, n+1); dp[1]=0;
    for(int i = 1; i<=n; ++i) cin>>a[i];
    for(int i = 1; i<=n; ++i) cin>>b[i];
    while(pq.size()) pq.pop();
    pq.push({-a[1], b[1]});
    for(int i=2; i<=n; ++i){
        while(pq.size() && pq.top().snd < i) pq.pop();
        if(pq.empty()) break;
        dp[i] = -pq.top().fst;
        pq.push({-(dp[i] + a[i]), b[i]});
    }
    ll ans = 0, sum = 0;
    for(int i = 1; i<=n; ++i){
        sum += a[i];
        ans = max(ans, sum - dp[i]);
    }cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
