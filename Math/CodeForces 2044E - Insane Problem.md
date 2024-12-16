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
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, k, r1, l1, l2, r2;

void solve(){        
    cin>>k>>l1>>r1>>l2>>r2;
    ll k_n = 1, rs = 0;
    while(k_n <= r2){
        ll min = ceil(l2/(k_n*1.0)), max = r2/k_n;
        min = std::max(min, l1); max = std::min(max, r1);
        if(max >= min) rs += max-min+1;
        k_n*=k;
    }cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
