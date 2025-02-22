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
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
int tt=1, n;
string s, t;
vec<int> acc;

bool solve(){        
    cin>>n>>s>>t;
    acc.assign(n, 0); acc[0]=s[0]=='1';
    for(int i=1; i<n; ++i) acc[i]=acc[i-1]+(s[i]=='1');
    for(int i=0; i<n; ++i) if(s[i]!=t[i] && acc[i]==0) return 0; 
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>tt;
    while(tt--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
