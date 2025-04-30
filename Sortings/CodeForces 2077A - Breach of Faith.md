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
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, x;
vec<ll> arr;
set<ll> l, r;

void solve(){        
    cin>>n; arr.resize(2*n);
    for(auto &i : arr) cin>>i;
    l.clear(); r.clear(); sort(ALL(arr));
    ll mx = arr.back(), cur=mx; arr.pop_back();
    for(int i=0; i<n; ++i) r.insert(arr.back()), arr.pop_back();
    while(arr.size()) l.insert(arr.back()), arr.pop_back();
    for(auto &i : r) cur+=i;
    for(auto &i : l) cur-=i;
    cout<<mx<<' ';
    while(l.size()) {
        cout<<*l.begin()<<' '<<*r.begin()<<' ';
        r.erase(r.begin()), l.erase(l.begin());
    }cout<<cur<<' '<<*r.begin()<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
