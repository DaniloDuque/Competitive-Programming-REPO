```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
const int MAX = 1e5+20, MOD = 1e9+7;
ll t=1, n, l, r, arr[MAX], ps[MAX];

void solve(){        
    cin>>n>>l>>r; 
    for(int i = 0; i<n; ++i) cin>>arr[i];
    partial_sum(arr, arr+n, 1+ps);
    int ans = 0;
    for(int i = 0; i<n; ++i){
        ll x = lower_bound(ps, ps+n+1, l+ps[i])-ps;
        if(x>n) continue;
        if(ps[x]-ps[i]<=r) ans++, i=x-1;
    }cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
