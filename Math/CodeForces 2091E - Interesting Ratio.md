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
const int MAX = 1e7+20, MOD = 1e9+7;
ll n, sv[MAX];

void init(){
    memset(sv, -1, sizeof(sv));
    for(ll i = 2; i<MAX; ++i)
        if(sv[i] < 0)
            for(ll j = 1LL*i*i; j<MAX; j+=i) sv[j] = i;
}

void solve(){        
    cin>>n;
    ll r = 0;
    for(int i=2; i<=n; ++i) if(sv[i]==-1) r+=n/i;
    cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
