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
ll n, arr[MAX];

pair<ll, ll> lin(ll a1, ll a2, ll n) {
    ll d = 1-n*n;
    if((a2-a1*n)%d) return {-1, -1};
    ll y = (a2-a1*n)/d, x = a1-y*n;
    return {x, y};
}

bool solve(){        
    cin>>n; 
    for(auto &i : span(arr, n)) cin>>i;
    auto [x, y] = lin(arr[0], arr[n-1], n);
    if(x<0 || y<0) return 0;
    for(int i=0; i<n; ++i) if(arr[i] != ((i+1)*x + (n-i)*y)) return 0;
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
