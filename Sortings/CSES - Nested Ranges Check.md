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
#define pll pair<ll, ll> 
const int MAX = 2e5+20, MOD = 1e9+7;
ll n;
vec<pll> arr, idx;
map<pll, ll> cnt1, cnt2;
 
void solve(){        
    cin>>n; arr.resize(n); 
    cnt1.clear(); cnt2.clear();
    for(auto &[x, y] : arr) cin>>x>>y;
    for(auto &i : arr) idx.pb(i);
    sort(ALL(arr), [](pll &a, pll &b) {
        if(a.fst == b.fst) return a.snd > b.snd;
        return a.fst < b.fst;
    });
    ll mn = LLONG_MAX, mx = 0;
    for(int i=n-1; i>=0; --i) {
        if(arr[i].snd >= mn) cnt1[arr[i]]++;
        mn = min(mn, arr[i].snd);
    }
    for(int i=0; i<n; ++i) {
        if(arr[i].snd <= mx) cnt2[arr[i]]++;
        mx = max(mx, arr[i].snd);
    }
    for(auto &i : idx) cout<<cnt1[i]<<' '; cout<<endl;
    for(auto &i : idx) cout<<cnt2[i]<<' '; cout<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
