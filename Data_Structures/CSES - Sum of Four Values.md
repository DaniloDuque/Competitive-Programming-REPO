```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n, x;
vec<ll> arr;
map<ll, vec<pll>> mp;
 
set<ll> solve(){        
    cin>>n>>x; 
    arr.resize(n); mp.clear();
    for(auto &i : arr) cin>>i;
    for(int i=0; i<n; ++i) 
        for(int j=i+1; j<n; ++j) 
            mp[arr[i]+arr[j]].pb({i+1, j+1});
    for(auto &[s1, v1] : mp) {
        ll s2 = x - s1;
        if(!mp.count(s2)) continue;
        auto &v2 = mp[s2];
        for (auto &[i1, j1] : v1) {
            for (auto &[i2, j2] : v2) {
                if (i1 != i2 && i1 != j2 && j1 != i2 && j1 != j2) {
                    return {i1, j1, i2, j2};
                }
            }
        }
    }
    return {};
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        auto sol = solve();
        if(sol.size()) for(auto &i : sol) cout<<i<<' '; 
        else cout<<"IMPOSSIBLE";
        cout<<endl;
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
