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
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, c, arr[MAX];

ll fun(ll m){
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += (arr[i] + 2*m) * (arr[i] + 2*m);
        if(sum > c) break; 
    }return sum;
}

ll bb(ll i, ll j) {
    while (i <= j) {
        ll m = i + (j - i) / 2, f = fun(m);
        if (f == c) return m;     
        if (f > c) j = m - 1;            
        else i = m + 1;            
    }return -1; 
}

void solve(){        
    cin >> n >> c;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << bb(1, 1e9) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
