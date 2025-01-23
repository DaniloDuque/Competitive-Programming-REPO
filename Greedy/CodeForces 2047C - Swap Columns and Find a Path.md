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
const int MAX = 5e3+20, MOD = 1e9+7;
int t=1, n, arr[2][MAX];

void solve(){        
    cin>>n;
    for(int i=0; i<2; ++i)
        for(int j=0; j<n; ++j)
            cin>>arr[i][j];
    vec<ll> best(n), all(n);
    ll best_sum = 0, rs = -MOD;
    for(int i=0; i<n; ++i) {
        best[i]=max(arr[0][i], arr[1][i]);
        all[i] = arr[0][i]+arr[1][i];
        best_sum += best[i];
    }
    for(int i=0; i<n; ++i) rs = max(rs, best_sum + all[i] - best[i]);
    cout<<rs<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
