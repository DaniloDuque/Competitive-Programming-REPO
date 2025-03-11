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
ll t=1, x;

void solve(){        
    cin>>x;
    ll y=0, i;
    for(i=0; !TEST(x, i); ++i);
    y|=(1<<i); 
    for(i=0; TEST(x, i); i++);
    y|=(1<<i); 
    if(y>= x || y+x <= (x^y) || x+(x^y) <= y || y+(x^y) <= x) {cout<<-1<<endl; return;}
    cout<<y<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
