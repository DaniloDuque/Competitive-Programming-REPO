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
ll n, m, k;
vec<ll> app, apr;
vec<pair<ll, ll>> pos;
set<ll> tkn;
 
int solve(){        
    cin>>n>>m>>k; pos.clear();
    app.resize(n); apr.resize(m);
    for(auto &i : app) cin>>i;
    for(auto &i : apr) cin>>i;
    sort(ALL(app)); sort(ALL(apr));
    for(auto &i : app) {
        int lb = lower_bound(ALL(apr), i-k)-apr.begin();
        int ub = upper_bound(ALL(apr), i+k)-apr.begin();
        pos.pb({lb, ub});
    }ll r = 0, cur = 0;
    for(auto &[x, y] : pos) {
        cur=max(cur, x);
        if(cur==y) continue;
        while(tkn.count(cur) && cur<y) cur++; 
        if(cur<y) r++, tkn.insert(cur);
    }
    return r;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
