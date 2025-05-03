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
ll n, q, l, r;
vec<ll> arr, da, acc;
vec<pair<ll, ll>> qs;

void solve(){        
    cin>>n>>q; da.assign(n+2, 0);
    arr.resize(n); acc.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    while(q--) {
        cin>>l>>r;
        qs.pb({l-1, r-1});
        da[l]++, da[r+1]--;
    }
    partial_sum(ALL(da), da.begin());
    priority_queue<pair<ll, ll>> pq;
    for(int i=1; i<=n; ++i) pq.push({da[i], i-1});
    while(pq.size()) {
        auto [x, i] = pq.top(); pq.pop();
        acc[i]=arr.back(); arr.pop_back();
    }
    ll rs = 0;
    partial_sum(ALL(acc), acc.begin());
    for(auto &[l, r] : qs) rs+=(acc[r]-((l)? acc[l-1] : 0));
    cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
