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
ll n;

ll s(ll x) {
    if(!x) return 0;
    return (x%10)+s(x/10);
}

ll solve(){        
    cin>>n; 
    for(int i=1; i<82; ++i) {
        ll x = (sqrt(i*i+4*n)-i)/2; 
        if(s(x)==i && x*x+i*x==n) return x;
    }return -1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
