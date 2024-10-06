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
const int MAX = 2e5+20;
ll t=1, x, y, z, k;

ll count(ll i, ll j, ll k){
    return (x-i+1) * (y-j+1) * (z-k+1);
}

void solve(){        
    cin>>x>>y>>z>>k;
    ll max = 0;
    for(ll i=1; i<=x; ++i)
        if(i<=k && !(k%i))
            for(ll j=1; j<=y; ++j)
                if(!(k%(i*j))) 
                    max = std::max(max, count(i, j, k/(i*j)));
    cout<<max<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
