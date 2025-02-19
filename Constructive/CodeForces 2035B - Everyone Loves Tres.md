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
int t=1, n;

void solve(){        
    cin>>n;
    int odd=0, even=0;
    string r(n, '3'); r[0]='6';
    for(int i=0; i<n; ++i) 
        if(i&1) odd+=(r[i]-'0');
        else even+=(r[i]-'0');
    for(int i=1; i<n; ++i) {
        if((i&1) && odd < even) r[i]='6', odd+=3;
        if(!(i&1) && even < odd) r[i]='6', even+=3;
    }
    if(odd != even) {cout<<-1<<endl; return;}
    reverse(ALL(r));
    cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
