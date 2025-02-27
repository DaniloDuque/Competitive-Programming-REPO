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
int t=1, n, x;
vec<ll> r;

bool valid(int y){
    for(int i=0; i<31; ++i) if(!TEST(x, i) && TEST(y, i)) return 0;
    return 1;
}

void solve(){        
    cin>>n>>x; r.clear(); 
    for(int i=0; i<n; ++i) {
        if(!valid(i)) break;
        r.pb(i);
    } 
    while(r.size()<n) r.pb(x);
    int acc = 0;
    for(auto &i : r) acc|=i;
    if(acc!=x) r.back()=x;
    for(auto &i : r) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
