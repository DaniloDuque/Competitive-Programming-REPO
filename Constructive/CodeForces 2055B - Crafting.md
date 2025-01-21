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
int t=1, n, a[MAX], b[MAX];

bool solve(){        
    cin>>n; 
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    int cnt = 0, mnm = MOD, idx = -1;
    for(int i=0; i<n; ++i) if(a[i] < b[i] && b[i]-a[i] < mnm) mnm=b[i]-a[i], idx=i, cnt++;
    if(cnt > 1) return 0;
    if(!cnt) return 1;
    for(int i=0; i<n; ++i){
        if(i!=idx && a[i]-b[i] < mnm) return 0;
    }return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
