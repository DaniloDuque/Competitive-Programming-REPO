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
ll n, arr[MAX], low[MAX], hgh[MAX];

void solve(){        
    cin>>n;
    for(auto &i : span(arr, n)) cin>>i;
    for(int i=0; i<n; ++i) cin>>low[i]>>hgh[i];
    ll cur = 0;
    for(int i=n-2; i>=0; --i) 
        hgh[i]=min(hgh[i], hgh[i+1]-(arr[i+1]==1));
    for(int i=0; i<n; ++i) {
        ll &l = low[i], &h = hgh[i];
        if(arr[i]==-1) arr[i]=(cur<h);
        cur+=arr[i];
        l=max(cur, l), h=min(cur, h);
        if(h<l) return void(cout<<-1<<endl);
    }
    for(auto &i : span(arr, n)) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
