```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e2+20;
ll t=1, n, m, mat[MAX][MAX];

ll fun(int x, int y){
    ll s = 0;
    for (int i = 0; i<max(m, n); i++) {
        if (x+i<n && y+i<m) s += mat[x+i][y+i]; 
        if (x-i>=0 && y-i>=0) s += mat[x-i][y-i]; 
    }
    for (int i = 0; i<max(n, m); i++) {
        if (x+i<n && y-i>=0) s += mat[x+i][y-i];
        if (x-i>=0 && y+i<m) s += mat[x-i][y+i]; 
    }
    return s - 3*mat[x][y]; 
}

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) 
        for(int j = 0; j<m; ++j) cin>>mat[i][j];
    ll max = 0;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
            max = std::max(max, fun(i, j));
    cout<<max<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
