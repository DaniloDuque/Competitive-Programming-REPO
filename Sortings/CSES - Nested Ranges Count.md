```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define pll pair<ll, ll>
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, i=0;
vec<pair<pair<ll, ll>, ll>> arr;
ordered_set<pll> ost;
vec<ll> ady, inc;

void solve(){        
    cin>>n; arr.resize(n);
    ady.assign(n, 0); inc.assign(n, 0);
    for(auto &[x, y] : arr) cin>>x.fst>>x.snd, y=i++;
    sort(ALL(arr), [](pair<pll, ll> &x, pair<pll, ll> &y){
        auto &[xf, xs] = x.fst; auto &[yf, ys] = y.fst;
        return (xf==yf)? xs>ys : xf<yf;
    });
    for(int i=n-1; i>=0; --i) {
        pll rng = {arr[i].fst.snd, -i};
        ost.insert(rng);
        ady[arr[i].snd]=ost.order_of_key(rng);
    }ost.clear();
    for(int i=0; i<n; ++i) {
        pll rng = {arr[i].fst.snd, -i};
        ost.insert(rng);
        inc[arr[i].snd]=ost.size()-ost.order_of_key(rng)-1;
    }
    for(auto &i : ady) cout<<i<<' '; cout<<endl;
    for(auto &i : inc) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
