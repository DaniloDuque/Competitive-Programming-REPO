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
ll n;

ll nine(ll k) {
    ll r = 0;
    while(k--) r*=10, r+=9;
    return r;
}

bool hasSeven(ll x) {
    if(!x) return 0;
    if(x%10 == 7) return 1;
    return hasSeven(x/10);
}

void solve(){        
    cin>>n;
    ll r = INT_MAX;
    for(int i=1; i<10; ++i) {
        ll ni = nine(i), cur=n, s=0;
        while(!hasSeven(cur)) cur+=ni, s++;
        r = min(r, s);
    }cout<<r<<endl;
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
