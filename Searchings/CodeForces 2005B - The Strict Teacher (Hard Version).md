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
const int MAX = 1e5+20;
int t=1, n, m, q, arr[MAX], p;

void solve(){        
    cin>>n>>m>>q;
    for(int i = 0; i<m; ++i) cin>>arr[i];
    sort(arr, arr+m);
    while(q--){
        cin>>p;
        int idx = lower_bound(arr, arr+m, p)-arr;
        if(idx == m) cout<<n-arr[m-1];
        else if(idx == 0) cout<<arr[0]-1;
        else cout<<(arr[idx]-arr[idx-1])/2;
        cout<<'\n';
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
