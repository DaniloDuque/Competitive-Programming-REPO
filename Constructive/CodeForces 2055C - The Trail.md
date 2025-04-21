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
const ll MAX = 1e3+20, MOD = 1e9+7;
ll n, m, mat[MAX][MAX];
string s;
vec<ll> r, c;

void upd(int i, int j, ll cur) {
    mat[i][j]=-cur;
    r[i]-=cur, c[j]-=cur;
}

void solve() {
    cin>>n>>m>>s;
    r.assign(n, 0); c.assign(m, 0);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) {
            cin>>mat[i][j];
            r[i]+=mat[i][j];
            c[j]+=mat[i][j];
        }
    for(int i=0, j=0, k=0; s[k]; ++k) {
        if(s[k]=='D') upd(i, j, r[i]), i++;
        else upd(i, j, c[j]), j++;
    }upd(n-1, m-1, r.back());
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) 
            cout<<mat[i][j]<<' ';
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
