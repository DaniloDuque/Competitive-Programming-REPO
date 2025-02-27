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
const int MAX = 2e3+20, MOD = 1e9+7;
int t=1, n, arr[MAX];
vec<vec<ll>> acc;

void solve(){        
    cin>>n; acc.assign(n, {});
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i=0; i<n; ++i) {
        acc[i].assign(n-i+1, 0);
        for(int k=1, j=i+1; j<n; ++j, ++k) {
            acc[i][k]=acc[i][k-1];
            if(arr[j]<arr[i]) acc[i][k]++;
            if(arr[j]>arr[i]) acc[i][k]--;
        } 
    }
    int l=1, r=1, mx=INT_MIN;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<acc[i].size(); ++j)
            if(acc[i][j] > mx) l=i+1, r=i+j+1, mx=acc[i][j];
    }cout<<l<<' '<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
