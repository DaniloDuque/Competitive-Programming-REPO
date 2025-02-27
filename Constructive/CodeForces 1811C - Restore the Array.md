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
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    vec<int> rslt(n, 0);
    for(int i=0; i<n-1; ++i) cin>>arr[i];
    rslt[0]=arr[0];
    for(int i=0; i<n-1; ++i) {
        if(max(rslt[i], rslt[i+1]) != arr[i]) rslt[i+1]=arr[i];
    }
    for(int i=n-1; i>0; --i) 
        if(max(rslt[i], rslt[i-1]) != arr[i-1]) rslt[i-1]=arr[i-1];
    for(auto i : rslt) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
