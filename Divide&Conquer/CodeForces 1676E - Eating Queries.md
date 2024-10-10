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
const int MAX = 2e5+20;
int t=1, n, q, arr[MAX], x;

void solve(){        
    cin>>n>>q;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(arr, arr+n, greater<int>()); partial_sum(arr, arr+n, arr); 
    while(q--){
        cin>>x;
        int idx = lower_bound(arr, arr+n, x)-arr;
        cout<<((x>arr[n-1])? -1 : idx+1)<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
