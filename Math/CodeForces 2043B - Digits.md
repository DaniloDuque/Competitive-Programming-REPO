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
int t=1, n, d;

void solve(){        
    cin>>n>>d;
    cout<<1<<' ';
    if(n>=3 || d%3 == 0) cout<<3<<' ';
    if(d==5) cout<<5<<' ';
    if(n>=3 || d==7) cout<<7<<' ';
    if(d==3 && n>=3 || d==6 && n>=3 ||d==9 ||n >=6) cout<<9<<' ';
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
