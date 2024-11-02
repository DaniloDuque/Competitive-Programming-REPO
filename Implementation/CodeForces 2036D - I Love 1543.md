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
int t=1, n, m;
vec<string> mat;
const string num = "1543";

int updateCyc(int s, int u){
    vec<char> cur; int r = 0;
    for(int i = u; i<m-u; ++i) cur.push_back(mat[s][i]);
    for(int i = s+1; i<n-s; ++i) cur.push_back(mat[i][m-1-u]);
    for(int i = m-u-2; i>=u; --i) cur.push_back(mat[n-s-1][i]);
    for(int i = n-s-2; i>s; --i) cur.push_back(mat[i][u]);
    for(int i = 0; i<3; ++i) cur.push_back(cur[i%cur.size()]);
    for(int i = 0; i+4<=cur.size(); ++i){
        string c = "";
        for(int j = 0; j<4; ++j) c+=cur[i+j];
        r += (c==num);
    }return r;
}

void solve(){        
    cin>>n>>m; mat.resize(n);
    for(auto &k : mat) cin>>k;
    int rs = 0;
    int l = 0, r = 0;
    while(l<n/2 && r<m/2) rs+=updateCyc(l, r), l++, r++;
    cout<<rs<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
