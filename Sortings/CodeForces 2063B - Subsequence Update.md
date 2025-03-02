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
int t=1, n, l, r;
vec<int> arr;

void solve(){        
    cin>>n>>l>>r; --l; arr.resize(n);
    for(auto &i : arr) cin>>i;
    vec<int> b(arr);
    sort(b.begin()+l, b.end());
    vec<int> a(arr);
    sort(a.begin(), a.begin()+r, greater<int>());
    ll sumA = 0, sumB = 0;
    for(int i=l; i<r; ++i) sumA+=a[i], sumB+=b[i];
    cout<<min(sumB, sumA)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
