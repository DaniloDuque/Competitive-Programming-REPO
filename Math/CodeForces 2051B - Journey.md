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
ll t=1, n, a, b, c;

int solve(){        
    cin>>n>>a>>b>>c;
    ll s = a+b+c, mod = n%s, d = 3 * (n/s);
    if(n <= s) return (n <= a)? 1 : (n <= b+a)? 2 : 3;
    if(!mod) return d;
    if(mod <= a) return d+1;
    if(mod <= a+b) return d+2; 
    return d+3;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
