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
const int MAX = 1e6+20, MOD = 1e9+7;
int t=1, n;

void solve(){        
    cin>>n;
    if(n==2 || n==3) {cout<<"NO SOLUTION"<<endl; return;}
    int i=1;
    for(int j=n-!(n&1); j>0; i++, j-=2) cout<<j<<' ';
    for(int j=n-(n&1); i<=n; ++i, j-=2) cout<<j<<' ';
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
