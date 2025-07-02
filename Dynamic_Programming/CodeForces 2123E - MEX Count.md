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
ll n, arr[MAX], diff[MAX];
map<ll, ll> mp;

void solve(){        
    cin>>n; mp.clear();
    for(auto &i : span(arr, n)) cin>>i, mp[i]++;
    for(int i=0; i<=n+2; ++i) diff[i]=0;
    sort(ALLN(arr, n));
    ll mex = 0;
    for(int i=0; i<n; ++i) mex += (arr[i]==mex);
    for(int i=0; i<=mex; ++i) diff[mp[i]]++, diff[n-i+1]--;
    ll ps = 0;
    for(int i=0; i<=n; ++i) {
        ps += diff[i];
        cout<<ps<<' ';
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
