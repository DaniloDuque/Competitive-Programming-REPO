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
int t=1, n;
vec<ll> arr;
map<ll, ll> vis, num;
 
void solve(){        
    cin>>n; arr.resize(n+1);
    for(int i=1; i<=n; ++i) cin>>arr[i];
    int r = 0, cur = 0;
    for(int i=1; i<=n; ++i) {
        if(!vis[arr[i]]) {cur++; vis[arr[i]]=i, num[i]=arr[i]; continue;} 
        ll idx = vis[arr[i]];
        vec<pair<ll, ll>> ids;
        for(auto &[x, y] : num){
            if(x > idx) break;
            ids.pb({x, y});
        }
        for(auto &[x, y] : ids) vis.erase(y), num.erase(x);
        r = max(r, cur), vis[arr[i]]=i, num[i]=arr[i], cur=vis.size();
    }cout<<max(cur, r)<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
