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
ll t=1, n, m, a[MAX], b[MAX];

bool solve(){        
    cin>>n>>m;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<m; ++i) cin>>b[i];
    a[0] = min(a[0], b[0]-a[0]);
    a[n-1] = max(a[n-1], b[0]-a[n-1]);
    for(int i=1; i<n-1; ++i){
        if(a[i] < a[i-1]) a[i] = max(a[i], b[0]-a[i]);
        else if(b[0]-a[i] >= a[i-1]) a[i] = min(a[i], b[0]-a[i]);
    }for(int i=0; i<n-1; ++i) if(a[i] > a[i+1]) return 0; 
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<((solve())? "YES" : "NO")<<endl;
    }return 0;
}
