```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 1e2+20, MOD = 1e9+7;
int t=1, n, arr[MAX], dp[MAX][MAX<<1];

bool OPT(int i, int a = 0, int b = 0){
    if(i==n) return a==b;
    int &cur = dp[i][a];
    if(cur != -1) return cur;
    return cur = OPT(i+1, a+arr[i], b) || OPT(i+1, a, b+arr[i]);
}

void solve(){        
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i<n; ++i) cin>>arr[i];
    cout<<((OPT(0))? "YES" : "NO")<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
