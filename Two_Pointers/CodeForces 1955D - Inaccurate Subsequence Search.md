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
ll n, m, k, x;
vec<ll> arr;
map<ll, ll> bcnt, acnt;

void solve(){        
    cin>>n>>m>>k; arr.resize(n);
    acnt.clear(); bcnt.clear();
    for(auto &i : arr) cin>>i;
    for(int i=0; i<m; ++i) cin>>x, bcnt[x]++, acnt[arr[i]]++;
    ll r=0, cur=0;
    for(auto &[x, y] : bcnt) cur+=min(y, acnt[x]);
    r+=(cur>=k);
    for(int i=1; i+m<=n; ++i) {
        cur-=(bcnt[arr[i-1]] && acnt[arr[i-1]]<=bcnt[arr[i-1]]);
        acnt[arr[i-1]]--;
        cur+=(acnt[arr[i+m-1]]<bcnt[arr[i+m-1]]);
        acnt[arr[i+m-1]]++;
        r+=(cur>=k);
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
