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
ll n, x, c;
vec<pll> arr;
 
set<ll> solve(){        
    cin>>n>>x; arr.resize(n);
    for(int i=0; i<n; ++i) cin>>c, arr[i]={c, i};
    sort(ALL(arr));
    for(int i=0; i<n; ++i) {
        ll trgt = x-arr[i].fst;
        ll l=0, r=n-1;
        while(l<r) {
            if(l==i) {++l; continue;}
            if(r==i) {--r; continue;}
            ll cur = arr[l].fst+arr[r].fst;
            if(cur == trgt) return {arr[l].snd, arr[r].snd, arr[i].snd};
            (cur < trgt)? ++l : --r;
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
        if(sol.size()) for(auto &i : sol) cout<<i+1<<' '; 
        else cout<<"IMPOSSIBLE";
        cout<<endl;
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
