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
const int MAX = 1e2+20, MOD = 1e9+7;
int t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<2*n; ++i) cin>>arr[i];
    int ones = 0, max = 0, copy;
    for(int i = 0; i<2*n; ++i) ones+=!!arr[i];
    max = std::min(ones, 2*n-ones);
    copy = (ones>2*n-ones)? 2*ones-2*n : 0;
    if(ones > 2*n-ones) max += copy&1;
    cout<<(ones&1)<<' '<<max<<'\n';    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
