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
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, x, in_deg[MAX], dp[MAX];
vector<int> G[MAX];

vec<int> Khan(){
    queue<int> Q; set<int> topSort;
    for(int i = 0; i<n; ++i) for(int &j : G[i]) ++in_deg[j];
    for(int i = 0; i<n; ++i) if(!in_deg[i]) Q.push(i);
    while(!Q.empty()){
        int c = Q.front(); Q.pop();
        topSort.insert(c);
        for(int &j : G[c]) if(!(--in_deg[j])) Q.push(j);
    }vec<int> rs;
    for(int i=0; i<n; ++i) if(!topSort.count(i)) rs.push_back(i);
    return rs;
}

int path(int i){
    int &cur = dp[i]; 
    if(cur != -1) return cur;
    for(int j : G[i]) cur = max(cur, 1 + path(j));
    return cur;
}

void solve(){        
    cin>>n; MSET(in_deg, 0, n+1);
    MSET(dp, -1, n+1); MSET(G, {}, n+1); 
    for(int i=0; i<n; ++i) cin>>x, G[i].push_back(x-1);
    for(int i : Khan()) dp[i] = 0;
    int rs = INT_MIN;
    for(int i=0; i<n; ++i) if(!in_deg[i] && dp[i]) rs = max(rs, path(i));
    cout<<max(2, rs+2)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
