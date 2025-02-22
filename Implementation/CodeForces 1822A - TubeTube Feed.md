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
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
int tt=1, n, t, a[MAX], b[MAX];

void solve(){        
    cin>>n>>t;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    for(int i=0; i<n; ++i) a[i]+=i;
    int r=-1, idx=-1;
    for(int i=0; i<n; ++i) 
        if(a[i]<=t && b[i]>=r) r=b[i], idx=i+1;
    cout<<idx<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>tt;
    while(tt--){
        solve();
    }return 0;
}
