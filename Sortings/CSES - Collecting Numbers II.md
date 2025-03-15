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
int t=1, n, a, b, m;
vec<ll> idx, arr;
 
ll calc(ll i, ll x) {
    int r = 0;
    if(idx[i-1] <= idx[i] && idx[i-1] > x) r++;
    if(idx[i-1] > idx[i] && idx[i-1] <= x) r--;
    if(idx[i+1] >= idx[i] && idx[i+1] < x) r++;
    if(idx[i+1] < idx[i] && idx[i+1] >= x) r--;
    return r;
}
 
void solve(){        
    cin>>n>>m; arr.resize(n+2); idx.resize(n+2);
    for(int i=1; i<=n; ++i) cin>>arr[i], idx[arr[i]]=i;
    arr[n+1]=idx[n+1]=n+1;
    int inv=1, cur=0;
    for(int i=1; i<=n; ++i) {
        if(cur > idx[i]) inv++;
        cur=idx[i];
    }
    while(m--) {
        cin>>a>>b;
        ll x = arr[a], y = arr[b];
        swap(arr[a], arr[b]);
        inv += calc(x, b);
        idx[x]=b;
        inv += calc(y, a);
        idx[y]=a;
        cout<<inv<<endl;
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
