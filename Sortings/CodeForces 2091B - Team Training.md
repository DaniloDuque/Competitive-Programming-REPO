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
ll t=1, n, x;
vec<ll> arr;

void solve(){        
    cin>>n>>x; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    ll r=0;
    while(arr.size() && arr.back() >= x) r++, arr.pop_back();
    for(int i=arr.size()-1; i>0;) {
        int j=1;
        while(i-j+1>=0 && arr[i-j+1]*j < x) j++;
        if(i-j+1 < 0) break;
        r++; i=i-j;
    }cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
