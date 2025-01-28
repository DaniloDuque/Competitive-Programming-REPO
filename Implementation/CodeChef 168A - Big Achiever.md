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
const int MAX = 4e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX];

void solve(){      
    cin>>n;
    for(int i=0; i<n; ++i) cin>>arr[i];
    int cur = 0;
    for(int i=0; i<n; ++i) {
        if(arr[i] > cur) cout<<1, cur=arr[i];
        else cout<<0;
        cout<<' ';
    }cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
