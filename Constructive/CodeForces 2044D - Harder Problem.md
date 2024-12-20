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
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX], b[MAX];
set<int> vis;

void solve(){      
    cin>>n; vis.clear();
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i=1; i<=n; ++i) vis.insert(i);
    for(int i=0; i<n; ++i){
        if(vis.count(arr[i])) vis.erase(arr[i]), b[i]=arr[i];
        else b[i]=*vis.begin(), vis.erase(b[i]);
    }for(int i=0; i<n; ++i) cout<<b[i]<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}