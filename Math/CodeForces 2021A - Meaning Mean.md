```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vec=vector<T>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define snd second
#define fst first
#define ll long long
const int MAX = 51;
int t=1, n;
vec<int> arr;

void solve(){        
    cin>>n;
    arr.assign(n, 0);
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(ALL(arr));
    int m = (arr[0]+arr[1])>>1;
    for(int i = 2; i<n; ++i) m = (m+arr[i])>>1;
    cout<<m<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
