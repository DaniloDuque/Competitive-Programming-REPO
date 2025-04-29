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
ll a, b, c;

bool solve(){        
    cin>>a>>b>>c;
    ll d = b-a;
    a+=d; c-=d;
    ll s = a+b+c;
    if(s%3) return 0;
    ll cur = s/3;
    return (c>=cur) && (2*(cur-a) == c-cur);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<(solve()? "YES":"NO")<<endl;
    }return 0;
}
