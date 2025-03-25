```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
const int MAX = 2e5+20, MOD = 1e9+7;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n, q, arr[MAX], x, y;
char ins;
ordered_set<pair<ll, ll>> st;

void solve(){        
    cin>>n>>q; st.clear();
    for(int i=1; i<=n; ++i) cin>>arr[i], st.insert({arr[i], i});
    while(q--) {
        cin>>ins>>x>>y;
        if(ins=='!') {
            st.erase({arr[x], x});
            arr[x]=y;
            st.insert({arr[x], x});
        } else cout<<st.order_of_key({y, MOD}) - st.order_of_key({x-1, MOD})<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
