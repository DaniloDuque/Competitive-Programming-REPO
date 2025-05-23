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
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n, d, m, r;
vec<pair<ll,ll>> arr;
map<ll, ll> mp;

inline ll accumSum(ll i, ll j) {
    return arr[j].snd - (i? arr[i-1].snd : 0);
}

void solve(){        
    cin>>n>>d;
    for(int i=0; i<n; ++i) cin>>m>>r, mp[m]+=r;
    for(auto &[m, r] : mp) arr.pb({m, r});
    for(int i=1; i<arr.size(); ++i) arr[i].snd+=arr[i-1].snd;
    ll i=0, j=0, rs=0;
    while(i<arr.size() && j<arr.size()) {
        auto &[x, y] = arr[i];
        while(j<arr.size()) {
            auto &[a, b] = arr[j];
            if(a-x+1 > d) break;
            j++;  
        };
        rs = max(accumSum(i, j-1), rs);
        i++;
        j = max(j, i);
    } cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
