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
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, a[MAX], b[MAX];

void solve(){        
    cin>>n; 
    for(int i = 0; i<n; ++i) cin>>a[i];
    for(int i = 0; i<n; ++i) cin>>b[i];
    ll mx = INT_MIN, cnt = 0;
    for(int i = 0; i<n; ++i) mx = max(mx, a[i]-b[i]); 
    for(int i = 0; i<n; ++i) cnt += (a[i]-b[i]==mx);
    cout<<cnt<<'\n';
    for(int i = 0; i<n; ++i) if(a[i]-b[i]==mx) cout<<i+1<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
