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
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int n;
vec<int> arr;

void solve(){        
    cin>>n; arr.resize(n);
    for(auto &i : arr) cin>>i;
    int id1=-1, id2=-1, mx=-1, mn=MOD;
    for(int i=0; i<n; ++i) if(mx < arr[i]) mx=arr[i], id1=i;
    for(int i=0; i<n; ++i) if(mn > arr[i]) mn=arr[i], id2=i;
    mn = min(id1, id2), mx = max(id1, id2);
    cout<<1+min(mn+(n-mx), min(mn+abs(mx-mn), (n-mx-1)+abs(mx-mn)))<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
