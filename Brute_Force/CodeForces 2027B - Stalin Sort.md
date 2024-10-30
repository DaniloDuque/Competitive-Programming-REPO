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
const int MAX = 2e3+20, MOD = 1e9+7;
int t=1, n, arr[MAX];

void solve(){        
    cin>>n; 
    for(int i = 0; i<n; ++i) cin>>arr[i];
    ll r = INT_MAX;
    for(int i = 0; i<n; ++i){
        ll sum = i;
        for(int j = i+1; j<n; ++j)
            if(arr[j]>arr[i]) sum++;
        r=min(r, sum);
    }cout<<r<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
