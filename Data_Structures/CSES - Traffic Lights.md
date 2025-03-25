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
#define pll pair<ll, ll>
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, x;
set<ll> arr;
set<pll, function<bool(pll, pll)>> st([](pll a, pll b) {
    if (a.snd - a.fst == b.snd - b.fst)
        return a.fst < b.fst;  
    return a.snd - a.fst > b.snd - b.fst;  
});
 
void solve(){        
    cin>>x>>n; arr.clear(), st.clear();
    arr.insert(0); arr.insert(x);
    st.insert({0, x});
    while(n--) {
        cin>>x; arr.insert(x);
        auto lb = arr.find(x);
        ll l = *prev(lb), r = *next(lb);
        st.erase({l, r}); st.insert({l, x}); st.insert({x, r});
        auto &[a, b] = *st.begin();
        cout<<b-a<<' ';
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
