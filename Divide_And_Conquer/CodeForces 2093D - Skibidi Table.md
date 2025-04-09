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
ll n, q, x, y;
string ins, t1 = "->";
vec<vec<ll>> base = {{1, 4}, {3, 2}};

ll cuad(ll x, ll y, ll n) {
    ll cur = 1LL<<(n-1);
    if(x < cur) return (y < cur)? 1 : 4;
    return (y < cur)? 3 : 2;
}

ll rec(ll x, ll y, ll k) {
    if(k == 1) return base[x][y];
    ll cur = 1LL << (k - 1), offset = 1LL << (2 * k - 2); 
    if(x < cur && y < cur) return rec(x, y, k - 1); 
    if(x >= cur && y >= cur) return offset + rec(x - cur, y - cur, k - 1); 
    if(x >= cur && y < cur) return 2 * offset + rec(x - cur, y, k - 1); 
    return 3 * offset + rec(x, y - cur, k - 1); 
}

pair<ll, ll> getCords(ll v, ll k) {
    if(k==1) {
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j)
                if(base[i][j] == v) return {i, j};
    }
    ll sz = 1LL<<(2*k-2), hlf = 1LL<<(k-1);
    if(v<=sz) return getCords(v, k-1);
    if(v<=2*sz) {
        auto [x, y] = getCords(v-sz, k-1);
        return {x+hlf, y+hlf}; 
    } 
    if(v<=3*sz) {
        auto [x, y] = getCords(v-2*sz, k-1);
        return {x+hlf, y}; 
    } 
    auto [x, y] = getCords(v-3*sz, k-1);
    return {x, y+hlf}; 
}

void solve(){        
    cin>>n>>q;
    while(q--) {
        cin>>ins>>x;
        if(ins == t1) { 
            cin>>y; x--, y--;
            cout<<rec(x, y, n)<<endl;
            continue;
        }
        auto [a, b] = getCords(x, n);
        cout<<a+1<<' '<<b+1<<endl;
    }
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
