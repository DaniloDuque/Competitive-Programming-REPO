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
#define pll pair<ll,ll>
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, i=0;
vec<pair<pll, ll>> arr;
priority_queue<pll, vec<pll>, greater<pll>> pq;
set<ll> ava;
vec<ll> ans;
 
void solve(){        
    cin>>n; arr.resize(n); ans.resize(n);
    for(int i=0; i<n; ++i) ava.insert(i);
    for(auto &[x, y] : arr) cin>>x.fst>>x.snd, y=i++;
    sort(ALL(arr));
    for(int i=0; i<n; ++i) {
        auto &[l, r] = arr[i].fst;
        while(pq.size() && pq.top().fst < l) ava.insert(pq.top().snd), pq.pop();
        ans[arr[i].snd]=*ava.begin();
        pq.push({r, *ava.begin()});
        ava.erase(ava.begin());
    }
    ava.clear();
    for(auto &i : ans) ava.insert(i);
    cout<<ava.size()<<endl;
    for(auto &i : ans) cout<<i+1<<' '; cout<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
