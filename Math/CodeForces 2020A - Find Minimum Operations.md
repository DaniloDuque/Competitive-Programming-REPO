```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr, x) (memset(arr, x, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, k;

ll minOPS(ll n, int c){
    if(!n) return 0;
    if(c==1) return n;
    if(c==n) return 1;
    if(c>n) return minOPS(n, c/k);
    return 1 + minOPS(n-c, c);
}

ll solve(){        
    cin>>n>>k;
    if(k==1) return n;
    ll curr = 1;
    while(curr*k<=n) curr*=k; 
    return minOPS(n, curr);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
