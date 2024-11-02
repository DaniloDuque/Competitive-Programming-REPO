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
const int MAX = 1e3+20, MOD = 1e9+7;
int t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    bool b = 1;
    for(int i = 1; i<n; ++i) if(abs(arr[i]-arr[i-1])!=5 && abs(arr[i]-arr[i-1])!=7) b = 0;
    cout<<((b)? "YES" : "NO")<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}