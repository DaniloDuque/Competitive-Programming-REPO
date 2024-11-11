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
int t=1, n, arr[MAX], ones;
vec<int> rs;

void solve(){        
    cin>>n; ones=0; rs.clear();
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i = 0; i<=30; ++i){
        int one = 0;
        for(int j=0; j<n; ++j) one += !!TEST(arr[j], i);
        if(one) rs.push_back(one);
    }
    if(!rs.size()) for(int i=1; i<=n; ++i) cout<<i<<' ';
    else{
        int g = rs[0];
        for(int i=1; i<rs.size(); ++i) g = gcd(g, rs[i]);
        for(int i=1; i<=g; ++i) if(!(g%i)) cout<<i<<' '; 
    }cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
