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
const int MAX = 5e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX], u, v;
pair<vec<int>, multiset<int>> G[MAX];

bool miniDfs(int i) {
    if(G[i].snd.find(arr[i]) != G[i].snd.end()) return 1;
    bool ans = 0;
    for(auto &j : G[i].fst) {
        G[j].snd.erase(G[j].snd.find(arr[i]));
        ans |= (G[j].snd.find(arr[i]) != G[j].snd.end());
        G[j].snd.insert(arr[i]);
    }return ans;
}

void solve(){        
    cin>>n; MSET(G, {}, n+1);
    for(int i=1; i<=n; ++i) cin>>arr[i];
    for(int i=0; i<n-1; ++i){
        cin>>u>>v;
        G[u].fst.push_back(v);
        G[v].fst.push_back(u);
        G[u].snd.insert(arr[v]);
        G[v].snd.insert(arr[u]);
    }string s(n, '0');
    for(int i=1; i<=n; ++i) if(miniDfs(i)) s[arr[i]-1]='1'; 
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
