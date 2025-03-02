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
int t=1, n;
vec<pair<int, int>> rslt;
 
int hanoi(int n, int src, int trgt, int aux) {
    if(n<=0) return 0;
    int m = 1+hanoi(n-1, src, aux, trgt);
    rslt.emplace_back(src, trgt);
    return m+hanoi(n-1, aux, trgt, src);
}
 
void solve(){        
    cin>>n;
    cout<<hanoi(n, 1, 3, 2)<<endl;
    for(auto &[x, y] : rslt) cout<<x<<' '<<y<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
