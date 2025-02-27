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
ll t=1, n, x, k;
string s;

ll solve(){        
    cin>>n>>x>>k>>s;
    ll p = x, i=0, r=0;
    for(; i<n && i<k;) {
        p+=(s[i]=='R')? 1 : -1;
        ++i;
        if(!p) break;
    }
    if((i==n && p) || i==k) return !p;
    k-=i;
    for(i=0; i<n && i<k;) {
        p+=(s[i]=='R')? 1 : -1;
        ++i;
        if(!p) break;
    }
    if(i==k || (i==n && p)) return 1 + !p;
    return 1+(k/i);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
