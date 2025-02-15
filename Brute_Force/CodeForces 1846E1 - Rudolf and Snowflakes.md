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
ll t=1, x;
set<ll> s;

void precalc(){
    for(int k=2; k<=1000; ++k){
        ll sum = 1+k, x = k*k;
        for(int n=2; n<=20; ++n) {
            sum+=x;
            if(sum > 1e6) break;
            s.insert(sum);
            x *= k;
        }
    }
}

bool solve(){        
    cin>>x;
    return s.count(x);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    precalc();
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
