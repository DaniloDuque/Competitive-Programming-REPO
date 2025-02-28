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
ll t=1, k;
 
ll exp(ll b, ll e) {
    if(!e) return 1;
    if(e&1) return b*exp(b*b, e>>1);
    return exp(b*b, e>>1);
}
 
int digitAt(ll n, ll i){
    while(i--) n/=10;
    return n%10;
}
 
int solve(){        
    cin>>k;
    ll t=9, j=1;
    for(; t*j<k; t*=10, ++j) k-=j*t;
    ll rslt = exp(10, j-1) + (k-1)/j;
    if(k%j) return digitAt(rslt, j-k%j);
    return rslt%10;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
