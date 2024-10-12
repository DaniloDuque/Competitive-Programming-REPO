```cpp
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, k, arr[MAX], sum, s, mxs;

void Kadane(){
    sum = 0, s = 0, mxs = 0;
    for(int i = 0; i<n;){
        sum += arr[i];
        s += arr[i++];
        mxs = max(mxs, s);
        s = max(s, 0LL);
    }
}

ll exp(ll b, ll e){
    if(!e) return 1;
    if(e&1) return (b*exp((b*b)%MOD, e>>1))%MOD;
    return exp((b*b)%MOD, e>>1)%MOD;
}

void solve(){        
    cin>>n>>k;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    Kadane();
    sum = (sum%MOD + MOD)%MOD;
    mxs %= MOD;
    cout<<(sum+mxs*exp(2, k)-mxs+MOD)%MOD<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
