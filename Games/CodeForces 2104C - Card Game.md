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
ll n;
string s;
vec<ll> a, b;

bool solve(){        
    cin>>n>>s;
    a.clear(), b.clear();
    for(int i=0; i<n; ++i) (s[i]=='A')? a.pb(i+1) : b.pb(i+1);
    if(n==2) return a[0]==1;
    if(a.size()<2) return 0;
    if(b.size()<2) return 1;
    return (a.back()==n) && (a[0]==1 || a[a.size()-2]==n-1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<(solve()? "Alice" : "Bob")<<endl;
    }return 0;
}
