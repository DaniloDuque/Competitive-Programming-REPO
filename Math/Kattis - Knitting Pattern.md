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
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, k;

ll solve(){        
    cin>>n>>k;
    if(n%k == 0) return 0;
    n-=k;
    return 2*((n/2)%k);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}