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
int t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 1; i<=n; ++i) cin>>arr[i];
    for(int i = 2; i<=n/2; ++i)
        if(n-i+2 <= n && arr[n-i+1] == arr[n-i+2] || arr[i]==arr[i-1]) swap(arr[i], arr[n-i+1]);
    int rslt = 0;
    for(int i = 2; i<=n; ++i) rslt += (arr[i]==arr[i-1]);
    cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
