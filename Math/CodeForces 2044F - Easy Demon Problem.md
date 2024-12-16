```cpp
#include <bits/stdc++.h>
#include <unordered_set>
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
ll t=1, n, m, q, x, arr[MAX], sum;
unordered_set<ll> a, b;

bool possible(){
    for(int i=1; i*i <= abs(x); ++i) {
        if(x%i) continue;
        int j = x/i;
        if((a.count(i) && b.count(j)) || (a.count(-i) && b.count(-j)) ||
           (a.count(-j) && b.count(-i)) || (a.count(j) && b.count(i))) return 1;
    }return 0;
}

void solve(){        
    cin>>n>>m>>q; a.clear(); b.clear(); sum=0;
    for(int i=0; i<n; ++i) cin>>arr[i], sum+=arr[i];
    for(int i=0; i<n; ++i) a.insert(sum-arr[i]);
    sum=0;
    for(int i=0; i<m; ++i) cin>>arr[i], sum+=arr[i];
    for(int i=0; i<m; ++i) b.insert(sum-arr[i]);
    while(q--){
        cin>>x;
        cout<<(possible()? "YES" : "NO")<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
