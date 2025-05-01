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
const int MAX = 3e5+20, MOD = 1e9+7;
ll n, k, acc[MAX];
string s;
vec<ll> arr;

bool check(ll m) {
    string w(n, 'R');
    for(int i=0; i<n; ++i) if(s[i]=='B' && arr[i]>m) w[i]='B';
    for(int i=0; i<n; ++i) {
        if(w[i]=='R') continue;
        for(int j=i-1; j>=0 && w[j]=='R' && arr[j]<=m; --j) w[j]='B';
    }
    ll mx = 0;
    for(int i=0; i<n; ++i) if(s[i]!=w[i]) mx=max(mx, arr[i]);
    w.erase(unique(ALL(w)), w.end());
    return mx<=m && count(ALL(w), 'B')<=k;
}

ll solve(){        
    cin>>n>>k>>s; arr.resize(n);
    for(auto &i : arr) cin>>i;
    ll l=0, r=1e9+1;
    while(l!=r) {
        ll m = (l+r)>>1;
        if(check(m)) r=m;
        else l=m+1;
    }return l;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
