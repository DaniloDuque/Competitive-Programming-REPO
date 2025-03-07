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
ll n;
vec<vec<int>> mat;
set<int> st;

void solve(){        
    cin>>n; mat.assign(n, vec<int>(n-1, 0));
    for(auto &r : mat) for(auto &i : r) cin>>i;
    st.clear();
    for(int i=1; i<=n; i++) st.insert(i);
    map<int, int> cnt;
    for(auto &r : mat) cnt[r[0]]++;
    int a, mx, b, mn;
    for(auto &[x, y] : cnt) {
        if(y==1) b=x, mn=y;
        else a=x, mx=y;
    }cout<<a<<' '<<b<<' ';
    st.erase(a); st.erase(b);
    for(int j=1; j<n-1; ++j) {
        for(int i=0; i<n; ++i) 
            if(st.count(mat[i][j])) {
                cout<<mat[i][j]<<' ';
                st.erase(mat[i][j]);
                break;
            }
    }if(st.size()) cout<<*st.begin();
    cout<<endl;
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
