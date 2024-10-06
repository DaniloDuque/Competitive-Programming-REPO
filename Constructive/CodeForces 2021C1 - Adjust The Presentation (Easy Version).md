```cpp
#include <bits/stdc++.h>
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
const int MAX = 2e5+20;
ll t=1, n, m, q, arr[MAX];
vec<int> b;
set<int> available;

bool good(){
    for(int j = 0, i = 0; i<m; ++i){
        if(arr[j]==b[i]) available.insert(arr[j++]);
        else if(!available.count(b[i])) return 0;
    }return 1;
}

void solve(){        
    cin>>n>>m>>q; b.assign(m, 0);
    available.clear();
    for(int i = 0; i<n; ++i) cin>>arr[i];
    for(int i = 0; i<m; ++i) cin>>b[i];
    cout<<((good())? "YA" : "TIDAK")<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
