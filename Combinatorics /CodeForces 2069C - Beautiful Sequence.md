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
const int MAX = 2e5+20, MOD = 998244353;
ll t=1, n, arr[MAX], acum[MAX][3];

void solve(){        
    cin>>n;
    for(int i=0; i<n; ++i) cin>>arr[i];
    acum[0][0]=arr[0]==1;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<3; ++j) acum[i][j]=acum[i-1][j];
        if(arr[i]==1) acum[i][0]++;
        if(arr[i]==2) acum[i][1]=(2*acum[i-1][1] + acum[i-1][0])%MOD;
        if(arr[i]==3) acum[i][2]=(acum[i-1][2] + acum[i-1][1])%MOD;
    }cout<<acum[n-1][2]<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
