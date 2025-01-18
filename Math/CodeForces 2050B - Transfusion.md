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
int t=1, n, arr[MAX];

bool solve(){        
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    ll s1 = 0, s2 = 0, d1 = n>>1, d2 = (n+1)>>1;
    for(int i=0; i<n; i++){
        s1+=(i&1)*arr[i];
        s2+=(!(i&1))*arr[i];
    }return s1/d1 == s2/d2 && !(s1%d1) && !(s2%d2);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
