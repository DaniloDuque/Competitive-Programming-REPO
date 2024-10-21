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
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[min(n-1, r+1)] <= arr[min(n-1, i+1)]) {
            r = i;
        }
    }vec<int> ans;
    for(int i = r+1; i<n; ++i) ans.push_back(arr[i]);
    ans.push_back(arr[r]);
    for(int i = r-1; i>=0; --i)
        if(arr[i]>arr[0]) ans.push_back(arr[i]);
        else {
            for(int j = 0; j<=i; ++j) ans.push_back(arr[j]);
            break;
        }
    for(int &i : ans) cout<<i<<' '; cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
