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
map<ll, ll> cnt;
vec<ll> arr;

void solve(){        
    cin>>n; arr.clear(); cnt.clear();
    while(n--) cin>>x, cnt[x]++;
    for(auto &[x, y] : cnt) for(int i=0; i<y/2; ++i) arr.pb(x);
    if(arr.size()<4) {cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;
    ll x1=arr[0], y1=arr[1], x2=arr[arr.size()-2], y2=arr.back(); 
    cout<<x1<<' '<<y1<<' ';
    cout<<x1<<' '<<y2<<' ';
    cout<<x2<<' '<<y1<<' ';
    cout<<x2<<' '<<y2<<endl;
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
