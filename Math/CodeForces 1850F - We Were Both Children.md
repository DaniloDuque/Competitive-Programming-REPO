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
ll t=1, n, arr[MAX], jmps[MAX], x, m;
map<ll, ll> cnt;

void solve(){        
    cin>>n; MSET(jmps, 0, n+1); cnt.clear();
    for(int i=1; i<=n; ++i) cin>>x, cnt[x]++;
    m = 0;
    for(auto &p : cnt) arr[m++]=p.fst;
    for(int i=0; i<m; ++i) 
        for(int j=arr[i]; j<=n; j+=arr[i]) jmps[j]+=cnt[arr[i]];
    cout<<*max_element(jmps, jmps+n+1)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
