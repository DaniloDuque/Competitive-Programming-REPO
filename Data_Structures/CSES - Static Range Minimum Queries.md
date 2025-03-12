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
#define fun min
#define K 18
const int MAX = 2e5+20, MOD = 1e9+7;
int n, q, l, r, arr[MAX], spt[K][1<<K]; // -> 2^K > n
 
void init(int *a){
    for(int i = 0; i<n; ++i) spt[0][i] = a[i];
    for(int k = 1; k<K; ++k)
        for(int i = 0; i<=n-(1<<k); ++i)
            spt[k][i] = fun(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
}
 
int query(int i, int j) {
    int k = 31-__builtin_clz(j-i);
    return fun(spt[k][i], spt[k][j-(1<<k)]);
}
 
void solve(){        
    cin>>n>>q; 
    for(int i=0; i<n; ++i) cin>>arr[i];
    init(arr);
    while(q--) {
        cin>>l>>r;
        cout<<query(l-1, r)<<endl;
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
