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
ll n, k;

bool isPrime(ll x) {
    if(x==1) return 0;
    if(x==2) return 1;
    if(!(x&1)) return 0;
    ll i=3;
    for(; i*i<x; ++i, ++i) {
        if(x%i) continue;
        return 0;
    }return i*i != x; 
}

bool solve(){        
    cin>>n>>k;
    if(n==1) return k==2;
    return isPrime(n) && (k==1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
