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
ll n, one[33], zero[33];
vec<ll> arr;

void solve(){        
    cin>>n; arr.resize(n);
    MSET(one, 0, 32); MSET(zero, 0, 32);
    for(auto &i : arr) {
        cin>>i;
        for(int b=0; b<30; ++b) one[b]+=!!TEST(i, b), zero[b]+=!TEST(i, b);
    }
    ll rs = 0;
    for(auto &i : arr) {
        ll cur = 0;
        for(int b=0; b<30; ++b) {
            if(TEST(i, b)) cur+=(zero[b]<<b);
            else cur+=(one[b]<<b);
        }rs = max(rs, cur);
    }cout<<rs<<endl;
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
