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
ll t=1, k;
vec<pair<ll, ll>> pnts;

ll Gauss(ll n) {
    return n*(n-1)/2;
}

void solve(){        
    cin>>k; pnts.clear();
    if(!k) {cout<<0<<endl; return;}
    ll x=-1e9;
    while(k>0) {
        ll j=0;
        for(ll i=0; Gauss(i+1)<=k; ++i, j=Gauss(i)) pnts.pb({x, x+i});
        k-=j;
        x+=1000;
    }
    cout<<pnts.size()<<endl;
    for(auto &[x, y] : pnts) cout<<x<<' '<<y<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
