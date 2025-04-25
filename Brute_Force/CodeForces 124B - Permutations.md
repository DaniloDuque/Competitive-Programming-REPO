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
ll n, m;
vec<string> arr;
vec<ll> ord;

string srt(string &s) {
    string r(ALL(s));
    for(int i=0; i<m; ++i) r[i]=s[ord[i]];
    return r;
}

void solve(){        
    cin>>n>>m; arr.resize(n);
    for(auto &i: arr) cin>>i;
    ord.resize(m); iota(ALL(ord), 0);
    ll diff = INT_MAX;
    do {
        vec<string> c(ALL(arr));
        for(auto &i : c) i=srt(i);
        sort(ALL(c));
        diff = min(diff, stoll(c.back())-stoll(c[0]));
    }while(next_permutation(ALL(ord)));
    cout<<diff<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
