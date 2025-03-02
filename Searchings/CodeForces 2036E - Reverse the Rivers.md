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
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, k, q, c, r, m;
char ins;
vec<vec<int>> mat;

void solve(){        
    cin>>n>>k>>q; mat.assign(k, vec<int>(n)); 
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<k; ++j)
            cin>>mat[j][i];
    for(int i = 1; i<n; ++i)
        for(int j = 0; j<k; ++j)
            mat[j][i]|=mat[j][i-1];
    while(q--){
        cin>>m;
        vec<int> rslt;
        int down = 0, up = n;
        while(m--){
            cin>>r>>ins>>c; --r;
            if(ins=='<') up = min(up, int(lower_bound(ALL(mat[r]), c)-mat[r].begin()));
            else down = max(down, int(upper_bound(ALL(mat[r]), c)-mat[r].begin()));
        }cout<<((down>=up)? -1 : down+1)<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
