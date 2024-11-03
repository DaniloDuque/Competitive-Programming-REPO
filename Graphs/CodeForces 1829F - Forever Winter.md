```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e2+20, MOD = 1e9+7;
int t=1, n, m, u, v, in[MAX];
map<int, int> cnt;

void solve(){        
    cin>>n>>m; cnt.clear(); 
    MSET(in, 0, n+1);
    while(m--){
        cin>>u>>v;
        in[u]++; in[v]++;
    }for(int i = 1; i<=n; ++i) cnt[in[i]]++;
    vec<int> cur;
    for(auto &p : cnt) cur.push_back(p.snd);
    sort(ALL(cur));
    if(cur.size()==3) cout<<cur[1]<<' '<<cur[2]/cur[1];
    else cout<<cur[0]-1<<' '<<cur[1]/(cur[0]-1);
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
