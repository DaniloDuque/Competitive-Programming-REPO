```cpp
#include <bits/stdc++.h>
#include <numeric>
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
const int MAX = 52, MOD = 1e9+7;
int t=1, n, arr[MAX], even, odd;

bool solve(){        
    cin>>n; even = odd = 0;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    for(int i = 0; i<n; ++i) (arr[i]&1)? odd++ : even++;
    return odd%2 == 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<((solve())? "YES" : "NO")<<endl;
    }return 0;
}
