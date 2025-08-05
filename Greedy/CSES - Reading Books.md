```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n;
vec<ll> arr;
 
ll solve(){        
    cin>>n; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    ll lrg = arr[n-1];
    ll sum = accumulate(ALLN(arr, n-1), 0LL);
    if(lrg <= sum) return lrg+sum;
    return lrg<<1;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        cout<<solve()<<endl;
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
