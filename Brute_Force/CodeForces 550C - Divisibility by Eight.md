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
string s;
vec<vec<ll>> acc;
ll rslt;

ll f(string &x) {
    if(x.empty()) return 0;
    ll r = 0;
    reverse(ALL(x));
    while(x.size()) r*=10, r+=x.back()-'0', x.pop_back();
    if(!(r%8)) {rslt=r; return 1;}
    return 0;
}

bool BT(int i, string c) {
    if(c.size()==3 || i==s.size()) return f(c);
    return BT(i+1, c+s[i]) || BT(i+1, c);
}

void solve(){        
    cin>>s;
    if(!BT(0, "")) cout<<"NO";
    else cout<<"YES"<<endl<<rslt;
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
