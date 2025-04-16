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
set<ll> valid;

void init() {
    for(int i=11; i<=1099; ++i) {
        for(int a=0; a<=1099/111; ++a) {
            bool t = 0;
            for(int b=0; b<=1099/11; ++b) if(i==a*111+b*11) {t=1; break;}
            if(t) valid.insert(i);
        }
    }
}

bool solve(){        
    cin>>n;
    if(n > 1099) return 1;
    return valid.count(n);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    init();
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
