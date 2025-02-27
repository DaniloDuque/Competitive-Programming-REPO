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
#define ll long long
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, k;
string s;

void solve(){        
    cin>>n>>k>>s;
    for(int i=0; i<n; ++i) {
        if(k+'0' > s[i]) {
            s.insert(s.begin()+i, k+'0');
            break;
        }
    }if(s.size()==n) s.pb(k+'0');
    cout<<s<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
