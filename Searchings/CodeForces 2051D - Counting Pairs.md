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
const int MAX = 3e5+20, MOD = 1e9+7;
ll t=1, n, x, y, arr[MAX];

void solve() {
    cin>>n>>x>>y;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    ll rs = 0, total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    for(int i = 0; i < n; i++) {
        ll cur = total - arr[i];
        ll lower = max(cur - y, arr[i]); 
        ll upper = cur - x;
        if(lower <= upper) {
            int lb = lower_bound(arr + i + 1, arr + n, lower) - arr;
            int ub = upper_bound(arr + i + 1, arr + n, upper) - arr;
            rs += ub - lb;
        }
    }cout<<rs<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
