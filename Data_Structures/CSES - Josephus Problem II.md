```cpp
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, k;
 
void solve(){        
    cin>>n>>k; indexed_set st;
    for(ll i=1; i<=n; ++i) st.insert(i);
    ll idx = k%n;
    while(n--) {
        auto x = st.find_by_order(idx);
        cout<<*x<<' ';
        st.erase(x);
        if(n) idx = (idx+k)%n;
    }cout<<endl;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
