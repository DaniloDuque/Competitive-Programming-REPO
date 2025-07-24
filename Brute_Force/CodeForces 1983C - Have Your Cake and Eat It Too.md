```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
ll n, arr[3][MAX], obj_sum;
vec<ll> perms;

map<ll, pair<ll, ll>> try_opt(ll f, ll s, ll t) {
    ll f_s=0, s_s=0, t_s=0, i=0, j=0;
    for(;f_s<obj_sum && i<n; ++i) f_s+=arr[f][i];
    j=i;
    for(;s_s<obj_sum && j<n; ++j) s_s+=arr[s][j];
    for(int k=j; k<n; ++k) t_s+=arr[t][k];
    if(min({f_s, s_s, t_s}) < obj_sum) return {};
    map<ll, pll> mp;
    mp[f] = {1, i};
    mp[s] = {i+1, j};
    mp[t] = {j+1, n};
    return mp;
}

vec<ll> solve() { 
    cin>>n;
    perms = {0, 1, 2};
    for(auto &r : arr) 
        for(auto &i : span(r, n)) 
            cin>>i;
    obj_sum = ceil(1.0 * accumulate(ALLN(arr[0], n), 0LL) / 3);
    do {
        auto rs = try_opt(perms[0], perms[1], perms[2]);
        vec<ll> r;
        for(auto &[_, x] : rs) r.pb(x.fst), r.pb(x.snd);
        if(rs.size() > 1) return r;
    } while(next_permutation(ALL(perms)));
    return {-1};
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        for(auto i : solve()) cout<<i<<' ';
        cout<<endl;
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
