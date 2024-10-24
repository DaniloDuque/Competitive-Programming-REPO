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
ll t=1, n, arr[MAX];
map<ll, ll> cnt;

void solve(){        
    cin>>n; 
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int i = 0, j = n-1;
    for(; i<n; ++i)
        if(arr[i]!=arr[0]){
            while(j>=0 && arr[j]==arr[0]) --j; 
            break;
        }
    int rslt = max(0, j-i+1);
    i = 0, j = n-1;
    for(;j>=0; --j)
        if(arr[j]!=arr[n-1]){
            while(i<n && arr[i]==arr[n-1]) ++i;
            break;
        }
    cout<<min(rslt, max(0, j-i+1))<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
