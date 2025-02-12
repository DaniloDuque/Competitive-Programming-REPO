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
ll t=1, n, m;
vec<vec<ll>> mat;

bool cmp(vec<ll> &a, vec<ll> &b){
    double xa = accumulate(ALL(a), 0)/(a.size()*1.0);
    double xb = accumulate(ALL(b), 0)/(b.size()*1.0);
    return xa > xb;
}

void solve(){         
    cin>>n>>m;
    mat.assign(n, vec<ll>(m, 0));
    for(auto &r : mat)
        for(auto &i : r) cin>>i;
    sort(ALL(mat), cmp);
    ll rs = 0, k = n*m;
    for(auto &r : mat)
        for(auto &i : r) 
            rs += i*k--;
    cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
