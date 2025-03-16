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
const int MAX = 1e3+20, MOD = 1e9+7;
ll n, q, x_1, y_1, x_2, y_2, mat[MAX][MAX];
char c;
 
void solve(){        
    cin>>n>>q; 
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) 
            cin>>c, mat[i][j]=(c=='*');
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=n; ++j) 
            mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
    while(q--) {
        cin>>x_1>>y_1>>x_2>>y_2; --x_1, --y_1;
        cout<<mat[x_2][y_2]-mat[x_2][y_1]-mat[x_1][y_2]+mat[x_1][y_1]<<endl;
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
