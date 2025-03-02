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
ll n, x;
vec<ll> arr;
 
void solve(){        
    cin>>n>>x; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    int r = 0;
    for(int i=0; i<arr.size();) {
        ll cur = arr.back();
        if(arr[i] <= x-cur) ++i;
        arr.pop_back();
        r++;
    }cout<<r<<endl;
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
