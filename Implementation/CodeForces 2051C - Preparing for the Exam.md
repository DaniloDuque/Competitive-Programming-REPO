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
const int MAX = 3e5+20, MOD = 1e9+7;
int t=1, n, m, k, arr[MAX], x;
set<int> qs;

void solve(){        
    cin>>n>>m>>k; qs.clear();
    for(int i=0; i<m; ++i) cin>>arr[i];
    for(int i=0; i<k; ++i) cin>>x, qs.insert(x);
    if(n==k) {
        for(int i=0; i<m; ++i) cout<<'1';cout<<endl;
        return;
    }
    if(k <= n-2){
        for(int i=0; i<m; ++i) cout<<'0'; cout<<endl;
        return;
    }
    set<int> fail;
    for(int j=1; j<=n; ++j) if(!qs.count(j)) fail.insert(j);
    for(int i=0; i<m; ++i) cout<<(fail.count(arr[i])? '1' : '0');
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
