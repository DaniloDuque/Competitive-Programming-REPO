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
ll n, k, x, sum;
vec<ll> arr, acum;

ll bb(ll lftSum) {
    ll i=1, j=k;
    while(i+1 < j) {
        ll m = (i+j)>>1;
        ll cur = sum*m-lftSum;
        if(cur > x) j=m;
        else i=m;
    }
    if(sum*i-lftSum >= x) return i;
    if(sum*j-lftSum >= x) return j;
    return k+1;
}

void solve(){        
    cin>>n>>k>>x; arr.resize(n); acum.resize(n);
    for(auto &i : arr) cin>>i;
    partial_sum(ALL(arr), acum.begin());
    ll r = 0; sum=acum.back();
    for(int i=0; i<n; ++i) {
        ll lftSum = ((i>0)? acum[i-1] : 0);
        r+=k-bb(lftSum)+1;
    }cout<<r<<endl;
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
