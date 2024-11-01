```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 1e3+20, MOD = 1e9+7;
ll t=1, n, m, mat[MAX][MAX], vis[MAX][MAX];

ll dfs(ll i, ll j){
    if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || !mat[i][j]) return 0;
    vis[i][j]=1;
    return mat[i][j] + dfs(i+1, j) + dfs(i, j+1) + dfs(i-1, j) + dfs(i, j-1);
}

void solve(){        
    cin>>n>>m; 
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j){
            cin>>mat[i][j];
            vis[i][j]=0;
        }
    ll r = 0;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
            if(!vis[i][j]) r = max(r, dfs(i, j));
    cout<<r<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
