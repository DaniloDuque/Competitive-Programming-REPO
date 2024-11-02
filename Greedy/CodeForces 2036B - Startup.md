```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, k, b[MAX], c[MAX];
map<ll, ll> earn;

void solve(){        
    cin>>n>>k; earn.clear();
    for(int i = 0; i<k; ++i) cin>>b[i]>>c[i];
    for(int i = 0; i<k; ++i) earn[b[i]]+=c[i];
    vec<ll> cur;
    for(auto &k : earn) cur.push_back(k.snd);
    sort(ALL(cur), greater<ll>());
    ll rslt = 0;
    for(int i = 0; i<min(n, (ll)cur.size()); i++) rslt += cur[i];
    cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
