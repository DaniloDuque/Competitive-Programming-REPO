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
vec<ll> arr;
vec<vec<ll>> dp;

ll rec(int i, int lst=0) {
    if(i==n) return 0;
    if(arr[i]==0) return 1+rec(i+1, 0);
    ll &cur = dp[i][lst];
    if(cur < INT_MAX) return cur;
    if((arr[i]==1 || arr[i]==3) && (lst!=1)) cur = min(cur, rec(i+1, 1));  
    if((arr[i]==2 || arr[i]==3) && (lst!=2)) cur = min(cur, rec(i+1, 2));
    return cur = min(1+rec(i+1, 0), cur);
}

void solve(){        
    cin>>n; arr.resize(n);
    dp.assign(n+1, vec<ll>(5, INT_MAX));
    for(auto &i : arr) cin>>i;
    cout<<rec(0)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
