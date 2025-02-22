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
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, m;
vec<vec<int>> mat;

void solve(){        
    cin>>n>>m;
    mat.assign(n, vec<int>(m, 0));
    for(auto &r : mat) for(auto &i : r) cin>>i;
    if(n==1 && m==1) {cout<<-1<<endl; return;}
    for(auto &r : mat) {
        int c = r.back();
        for(int i=r.size()-1; i>0; --i) r[i]=r[i-1];
        r[0]=c;
    }
    vec<int> f = mat[n-1];
    for(int i=n-1; i>0; --i) mat[i]=mat[i-1];
    mat[0] = f;
    for(auto &r : mat) {
        for(auto &i : r) cout<<i<<' ';
        cout<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
