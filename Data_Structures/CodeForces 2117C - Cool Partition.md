```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n, arr[MAX];

void solve(){        
    cin>>n;
    for(auto &i : span(arr, n)) cin>>i;
    set<ll> cur, pst; pst.insert(arr[0]);
    ll rslt = 1;
    for(int i=1; i<n; ++i) {
        pst.erase(arr[i]);
        cur.insert(arr[i]);
        if(pst.empty()) {
            rslt++;
            pst = cur;
            cur.clear();
        }
    }cout<<rslt<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
