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
ll n, k;
vec<ll> arr;

bool chck(ll m) {
    set<ll> st;
    ll rs=0, sum=0;
    for(auto &i : arr) {
        if(i<m && !st.count(i)) st.insert(i), sum++;
        if(sum==m) {
            sum=0;
            st.clear();
            rs++;
        }
    }return rs >= k;
}

void solve(){        
    cin>>n>>k; arr.resize(n);
    for(auto &i : arr) cin>>i;
    ll l=0, r=n+1;
    while(l+1 < r) {
        ll m = (l+r)>>1;
        if(chck(m)) l=m;
        else r=m;
    }cout<<l<<endl;
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
