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
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, k;

void solve(){        
    cin>>n>>k;
    if(n==1 || (n+1)/2 == k){cout<<"1\n1\n"; return;}
    if(n==k){cout<<"-1\n"; return;}
    if(k&1 && n-(k+1)>0 && k>1 && (n-(k+1))&1) {cout<<3<<'\n'<<1<<' '<<k-1<<' '<<k+2<<'\n'; return;}
    if(!(k&1)){cout<<3<<'\n'<<1<<' '<<k<<' '<<k+1<<'\n'; return;}
    cout<<"-1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
