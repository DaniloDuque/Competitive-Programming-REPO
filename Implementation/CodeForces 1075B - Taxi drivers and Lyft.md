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
int t=1, n, m, arr[MAX], dri[MAX], rght[MAX], lft[MAX];
map<int, int> memo;

void solve(){        
    cin>>n>>m;
    for(int i=1; i<=n+m; ++i) cin>>arr[i];
    for(int i=1; i<=n+m; ++i) cin>>dri[i];
    for(int i=1; i<=n+m; ++i) if(dri[i]) memo[arr[i]]=0;
    lft[1]=dri[1]*arr[1]; rght[n+m]=dri[n+m]*arr[n+m];
    for(int i=2; i<=n+m; ++i) lft[i] = dri[i]? arr[i]: lft[i-1]; 
    for(int i=n+m-1; i>0; --i) rght[i] = dri[i]? arr[i]: rght[i+1];
    for(int i=1; i<=n+m; ++i){
        if(dri[i]) continue;
        if(!lft[i] || (rght[i] && rght[i]-arr[i] < arr[i]-lft[i])) ++memo[rght[i]];
        else ++memo[lft[i]];
    }
    for(auto &[_, x] : memo) cout<<x<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
