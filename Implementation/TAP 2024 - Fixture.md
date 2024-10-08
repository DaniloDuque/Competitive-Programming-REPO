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
const int MAX = 1e2+20;
int t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int c = 0, pnts = 0;
    for(int i = 0; i<n; ++i){
        if(arr[i]) pnts++, c++;
        else c=0, pnts--;
        if(c>=3) pnts++;
    }cout<<pnts<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
