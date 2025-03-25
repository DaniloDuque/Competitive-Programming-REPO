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
ll n;
 
void solve(){        
    cin>>n;
    set<ll> st; vec<ll> vc;
    for(int i=1; i<=n; ++i) st.insert(i);
    while(st.size() > 1) {
        int j=0; vc.clear();
        for(auto &i : st) {
            if(j&1) cout<<i<<' ', vc.pb(i);
            j++;
        }if(st.size()&1) cout<<*st.begin()<<' ', st.erase(st.begin());
        for(auto &i : vc) st.erase(i);
    }cout<<*st.begin()<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
