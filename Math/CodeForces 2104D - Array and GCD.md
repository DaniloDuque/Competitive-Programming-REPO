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
const int MAX = 6e6+20, MOD = 1e9+7;
ll n, sv[MAX];
vec<ll> arr, primes;

void init(){
    memset(sv, -1, sizeof(sv));
    for(ll i = 2; i<MAX; ++i)
        if(sv[i] < 0)
            for(ll j = 1LL*i*i; j<MAX; j+=i) sv[j] = i;
}

void solve(){        
    cin>>n; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr), greater<ll>());
    ll sum = accumulate(ALL(arr), 0LL), i=n-1;
    while(i>=0 && sum < primes[i]) sum-=arr[i--];
    cout<<n-i-1<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    for(int i=2; i<MAX; ++i) if(sv[i]==-1) primes.pb(i);
    partial_sum(ALL(primes), primes.begin());
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
