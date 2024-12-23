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
int t=1, n, a[MAX], b[MAX];

void solve(){        
    cin>>n;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    int rs = a[n-1];
    for(int i=n-2, j=n-1; i>=0; --j, --i){
        if(a[i]>b[j]) rs+=a[i]-b[j];
    }cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
