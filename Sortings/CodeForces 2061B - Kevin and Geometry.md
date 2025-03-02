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
const int MAX = 2e5+20, MOD = 1e9+7;
int t = 1, n;
vec<int> arr;

void solve(){
    cin>>n; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    int idx = -1, base = -1;
    for(int i=0; i<n-1; ++i)
        if(arr[i]==arr[i+1]){
            idx=i;
            base=arr[i];
        }
    if(base==-1){cout<<-1<<endl; return;}
    arr[idx]=arr[idx+1]=0;
    sort(ALL(arr));
    for(int i=2; i<n-1; ++i)
        if(2*base > abs(arr[i]-arr[i+1])) {cout<<base<<' '<<base<<' '<<arr[i]<<' '<<arr[i+1]<<endl; return;}
    cout<<-1<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
