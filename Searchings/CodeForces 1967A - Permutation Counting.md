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
ll n, k, arr[MAX];

inline bool check(ll x) {
    ll r = 0;
    for(auto &i : span(arr, n)) {
        if(i<x) r+=x-i;
        if(r>k) return 0;
    }
    return r<=k;
}

ll solve(){        
    cin>>n>>k;
    for(auto &i : span(arr, n)) cin>>i;
    ll l=1, r=1e18;
    while(l + 1 < r) {
        ll m = (l + r) >> 1;
        if(check(m)) l = m;  
        else r = m;
    }
    ll more=0, tot=(check(r)? r : l);
    for(auto &i : span(arr, n)) {
        if(i < tot) k-=tot-i;
        if(i > tot) more++;
    }
    return tot+(n-1)*(tot-1)+more+k;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        cout<<solve()<<endl;
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
