```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, T, ns[MAX], ks[MAX]; 

ll exp(ll b, int e){
    if(!e) return 1;
    if(e&1) return (b*exp((b*b)%MOD, e>>1))%MOD;
    return exp((b*b)%MOD, e>>1);
}

void solve(){        
    cin>>T;
    for(int i = 0; i<T; ++i) cin>>ns[i];
    for(int i = 0; i<T; ++i) cin>>ks[i];
    for(int i = 0; i<T; ++i) cout<<exp(2, ks[i])<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
