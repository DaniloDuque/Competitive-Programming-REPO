```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 1e3+20;
int t=1, n, dp[2][MAX][500];
vec<int> arr[MAX];

int maxValue(int i, int t, int v){
    if(t>480 || i>=n) return 0;
    int &curr = dp[v][i][t];
    if(curr != -1) return curr;
    if(t + 3*arr[i][0] > 780) return curr = maxValue(i+1, t, v);
    return curr = max(arr[i][v+1] + maxValue(i+1, t+3*arr[i][0], v), maxValue(i+1, t, v));
}

void solve(){        
    cin>>n; memset(dp, -1, sizeof(dp)); 
    for(int i = 0; i<n; ++i) arr[i].assign(3, 0), cin>>arr[i][0];
    for(int i = 0; i<n; ++i) cin>>arr[i][1];
    for(int i = 0; i<n; ++i) cin>>arr[i][2];
    sort(arr, arr+n);
    int J = maxValue(0, 0, 0), F = maxValue(0, 0, 1);
    cout<<((J==F)? "EITHER" : (J>F)? "PLEASURE" : "FAME")<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
