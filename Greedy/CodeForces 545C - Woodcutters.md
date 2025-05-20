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
pair<ll, ll> arr[MAX]; 

void solve(){        
    cin>>n;
    for(auto &[x, y] : span(arr, n)) cin>>x>>y;
    if(n==1) return void(cout<<1<<endl);
    ll rs=2, lst=arr[0].fst;
    for(int i=1; i<n-1; ++i) {
        auto &[x, h] = arr[i];
        ll l=arr[i-1].fst, r=arr[i+1].fst;
        if(x-h > lst) rs++, lst=x;
        else if(x+h < r) rs++, lst=x+h;
        else lst=x;
    }cout<<rs<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
