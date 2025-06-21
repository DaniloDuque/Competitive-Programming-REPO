```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n;
vec<ll> arr;

void solve(){        
    cin>>n; arr.resize(n+2);
    arr[0]=arr.back()=-MOD;
    for(int i=1; i<=n; ++i) cin>>arr[i];
    arr.erase(unique(ALL(arr)), arr.end());
    ll r = 0;
    for(int i=1; i<arr.size()-1; ++i) if(max(arr[i-1], arr[i+1]) < arr[i]) r++;
    cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
