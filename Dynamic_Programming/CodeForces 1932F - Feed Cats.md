```cpp
#include <bits/stdc++.h>
#include <set>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 1e6+20, MOD = 1e9+7;
int t=1, n, m, l, r, dp[MAX];
multiset<int> in_rng;
vec<int> st;
vec<vec<int>> del;

void solve(){        
    cin>>n>>m;
    del.assign(n+1, {}); st.assign(n+1, 0); 
    in_rng.clear(); memset(dp, 0, (n+1)*sizeof(int));
    while(m--){
        cin>>l>>r;
        st[l]++;
        del[r].push_back(l);
    }
    for(int i = 1; i<=n; ++i){
        dp[i]=dp[i-1];
        for(int j=0; j<st[i]; ++j) in_rng.insert(i);
        if(in_rng.size()) dp[i]=max(dp[i], int(dp[*in_rng.begin()-1]+in_rng.size()));
        for(int c : del[i]) in_rng.erase(in_rng.find(c));
    }cout<<dp[n]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
