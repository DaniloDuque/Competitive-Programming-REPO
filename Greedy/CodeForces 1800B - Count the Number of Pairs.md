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
ll n, k;
string s;
map<char, ll> mp;

void solve(){        
    cin>>n>>k>>s; mp.clear();
    for(auto &i : s) mp[i]++;
    ll r = 0;
    for(char i='A'; i<='Z'; ++i) {
        if(!k) break;
        ll &cU = mp[i], &cL = mp[i+32];
        if(!cU && !cL) continue;
        ll &mn = (cL < cU)? cL : cU;
        ll &mx = (cL > cU)? cL : cU;
        while(k && mn+1 < mx) {
            k--; mn++; mx--;
        }
    }for(char i='A'; i<='Z'; ++i) r+=min(mp[i], mp[i+32]);
    cout<<r<<endl;
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
