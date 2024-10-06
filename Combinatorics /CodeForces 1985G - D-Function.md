```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vec=vector<T>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, l, r, k;

ll exp(ll b, ll e){
    if(!e) return 1;
    if(e&1) return (b*exp((b*b)%MOD, e>>1))%MOD;
    return exp((b*b)%MOD, e>>1)%MOD;
}

void solve(){        
    cin>>l>>r>>k;
    cout<<(MOD + exp(9/k + 1, r) - exp(9/k + 1, l))%MOD<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
