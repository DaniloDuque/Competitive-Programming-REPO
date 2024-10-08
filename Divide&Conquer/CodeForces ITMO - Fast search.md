```cpp
#include <algorithm>
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
int t=1, n, q, l, r, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(arr, arr+n);
    cin>>q;
    while(q--){
        cin>>l>>r;
        int lb = lower_bound(arr, arr+n, l)-arr;
        int ub = upper_bound(arr, arr+n, r)-arr;
        cout<<ub-lb<<' ';
    }cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
