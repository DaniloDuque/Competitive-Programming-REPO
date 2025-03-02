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
const ll MAX = 2e5+20, MAXX = 1e12;
ll t=1, n, x, arr[MAX];

bool up(ll m){
    ll water = 0;
    for(int i=0; i<n && water<=x; ++i) water+=max(0LL, m-arr[i]);
    return water <= x;
}

void solve(){        
    cin>>n>>x;
    for(int i=0; i<n; ++i) cin>>arr[i];
    ll i=1, j=MAXX;
    while(j>=i){
        ll m = (i+j)>>1;
        up(m)? i=m+1 : j=m-1;
    }cout<<j<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
