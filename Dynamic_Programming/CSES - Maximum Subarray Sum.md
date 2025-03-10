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
 
void solve(){        
    cin>>n; arr.resize(n);
    for(auto &i : arr) cin>>i;
    ll s = 0, mxs = 0;
    for(int i = 0; i<n;){
        s += arr[i++];
        mxs = max(mxs, s);
        s = max(s, 0LL);
    }if(!mxs) mxs = *max_element(ALL(arr));
    cout<<mxs<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
