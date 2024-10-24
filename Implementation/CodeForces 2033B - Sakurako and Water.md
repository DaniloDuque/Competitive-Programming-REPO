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
const int MAX = 5e2+20, MOD = 1e9+7;
int t=1, n, mat[MAX][MAX];

int lake(int i, int j){
    int m = INT_MAX;
    while(i<n && j<n){
        m = min(m, mat[i][j]);
        i++; ++j;
    }return (m<0)*abs(m);
}

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<n; ++j)
            cin>>mat[i][j];

    int rslt = lake(0, 0);
    for(int i = 1; i<n; ++i) rslt += lake(0, i)+lake(i, 0);
    cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
