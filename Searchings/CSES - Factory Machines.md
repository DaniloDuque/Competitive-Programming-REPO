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
ll n, t;
vec<ll> arr;
 
bool check(ll m) {
    ll r=0;
    for(auto &i : arr) {
        if(r>=t) return 1;
        r+=m/i;
    }return r>=t;
}
 
void solve(){        
    cin>>n>>t; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    ll l=0, r=arr.back()*t+1;
    while(l!=r) {
        ll m = (l+r)>>1;
        if(check(m)) r=m;
        else l=m+1;
    }cout<<l<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        solve();
    }return 0;
}
