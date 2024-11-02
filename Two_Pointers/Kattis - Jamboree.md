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
const int MAX = 2e2+20, MOD = 1e9+7;
ll t=1, n, m, arr[MAX];

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(arr, arr+n);
    ll rs = 0, l = 0, r = min(n, (n-m)*2 - 1);
    while(l < r){
        rs = max(rs, arr[l]+arr[r]);
        ++l, --r;
    }cout<<max(arr[n-1], rs)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
