```cpp
#include <bits/stdc++.h>
#include <climits>
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
const ll MAX = 1e3+20, MOD = 1e9+7;
string a, b, c;
ll dp[MAX][MAX];

void solve(){        
    cin>>a>>b>>c;
    ll n=a.size(), m=b.size();
    for(int i=0; i<=n; ++i) 
        for(int j=0; j<=m; ++j) 
                dp[i][j]=LLONG_MAX;
    dp[0][0]=0;
    for(int i=0; i<n; ++i) dp[i+1][0]=dp[i][0]+(a[i]!=c[i]);
    for(int i=0; i<m; ++i) dp[0][i+1]=dp[0][i]+(b[i]!=c[i]);
    for(int i=1; i<=n; ++i) 
        for(int j=1; j<=m; ++j) {
            dp[i][j] = min(dp[i-1][j]+(a[i-1]!=c[i+j-1]), dp[i][j-1]+(b[j-1]!=c[j+i-1]));
        }
    cout<<dp[n][m]<<endl;
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
