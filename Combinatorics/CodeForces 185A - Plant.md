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
ll t=1, n;

ll exp(ll b, ll e){
    if(!e) return 1;
    if(e&1) return (b*exp((b*b)%MOD, e>>1))%MOD;
    return exp((b*b)%MOD, e>>1)%MOD;
}

void solve(){        
    cin>>n;
    if(!n) {cout<<1<<endl; return;}
    cout<<(exp(2, 2*n-1)%MOD + exp(2, n-1)%MOD)%MOD<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
