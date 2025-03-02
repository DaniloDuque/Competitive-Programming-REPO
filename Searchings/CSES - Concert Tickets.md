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
ll n, m, c, x;
multiset<ll> st;
 
void solve(){        
    cin>>n>>m; st.clear();
    for(int i=0; i<n; ++i) cin>>x, st.insert(x);
    while(m--) {
        cin>>c;
        auto it = st.lower_bound(c);
        if(*it == c) cout<<c<<endl, st.erase(it);
        else if(it == st.begin()) cout<<-1<<endl;
        else --it, cout<<*it<<endl, st.erase(it);
    }
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
