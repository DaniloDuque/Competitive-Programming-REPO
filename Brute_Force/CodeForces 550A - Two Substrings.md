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
string s;
vec<ll> ab, ba;

bool solve(){        
    cin>>s;
    for(int i=0; i<s.size()-1; ++i) if(s[i]=='A' && s[i+1]=='B') ab.pb(i);
    for(int i=0; i<s.size()-1; ++i) if(s[i]=='B' && s[i+1]=='A') ba.pb(i);
    for(auto &i : ab) 
        for(auto &j : ba) 
            if(abs(i-j)>1) return 1;
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
