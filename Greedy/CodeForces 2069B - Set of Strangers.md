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
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, m;
vec<vec<ll>> mat;
map<ll, ll> cnt, clr, ngh;

void solve(){        
    cin>>n>>m; cnt.clear();
    clr.clear(); ngh.clear();
    mat.assign(n, vec<ll>(m, 0));
    for(auto &r : mat) for(auto &i : r) cin>>i;
    for(auto &r : mat) for(auto &i : r) clr[i]++;
    for(ll i=0; i<n; ++i)
        for(ll j=0; j<m; ++j){
            if(ngh[mat[i][j]]==2) continue;
            ngh[mat[i][j]]=1;
            if(i>0 && mat[i][j]==mat[i-1][j]) ngh[mat[i][j]]++;
            else if(i+1<n && mat[i][j]==mat[i+1][j]) ngh[mat[i][j]]++;
            else if(j>0 && mat[i][j]==mat[i][j-1]) ngh[mat[i][j]]++;
            else if(j+1<m && mat[i][j]==mat[i][j+1]) ngh[mat[i][j]]++;
        }
    ll r = 0, s=0, mx=-1;
    for(auto x : clr) s+=!!x.snd;
    for(auto x : ngh) r+=x.snd;
    for(auto x : ngh) mx=max(mx, x.snd);
    cout<<max(s-1, r-mx)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
