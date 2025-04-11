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
ll n, m, a[MAX], b[MAX], c[MAX];
vec<ll> arr;

void chck(ll a, ll b, ll c) {
    auto it = lower_bound(ALL(arr), b);
    ll cur = 4*a*c - b*b, k = *it;
    auto f = [&](ll i) {
        return i*i - 2*b*i;
    };
    if(it != arr.end() && f(k) < cur) { cout<<"YES\n"<<k<<endl; return;}
    if(it == arr.begin()) {cout<<"NO"<<endl; return;}
    it = prev(it); k = *it;
    if(f(k) < cur) { cout<<"YES\n"<<k<<endl; return;}
    cout<<"NO"<<endl;
}

void solve(){        
    cin>>n>>m; arr.resize(n);
    for(auto &i : arr) cin>>i;
    for(int i=0; i<m; ++i) cin>>a[i]>>b[i]>>c[i];
    sort(ALL(arr));
    for(int i=0; i<m; ++i) chck(a[i], b[i], c[i]);
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
