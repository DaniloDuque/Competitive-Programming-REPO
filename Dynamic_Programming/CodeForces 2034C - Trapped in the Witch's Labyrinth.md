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
ll n, m;
vec<string> mat;
vec<vec<ll>> dp;
map<char, pair<int, int>> mv;

int dfs(int i, int j, char lst=0) {
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    ll &cur = dp[i][j];
    if(cur==2) cur=1;
    if(cur>-1) return cur;
    cur=2;
    if(mat[i][j]!='?') return cur=dfs(i+mv[mat[i][j]].fst, j+mv[mat[i][j]].snd, mat[i][j]);
    if(lst) {
        mat[i][j]=(lst=='D')? 'U': (lst=='U')? 'D' : (lst=='L')? 'R' : 'L';
        return cur=1;
    }return cur=max(max(dfs(i-1, j), dfs(i+1, j)), max(dfs(i, j-1), dfs(i, j+1)));
}

void solve(){        
    cin>>n>>m; mat.resize(n);
    for(auto &s : mat) cin>>s;
    dp.assign(n, vec<ll>(m, -1));
    for(int i=0; i<n; ++i) 
        for(int j=0; j<m; ++j) 
            dfs(i, j);
    ll rs = 0;
    for(auto &r : dp) rs+=accumulate(ALL(r), 0);
    cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    mv['D'] = {1, 0}; mv['U'] = {-1, 0};
    mv['L'] = {0, -1};mv['R'] = {0, 1};
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
