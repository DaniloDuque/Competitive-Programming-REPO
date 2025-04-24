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
ll n, k;
vec<string> arr, names, rs;

void solve(){        
    cin>>n>>k; arr.resize(n-k+1);
    for(auto &i : arr) cin>>i;
    for(char i='A'; i<'F'; ++i) 
        for(char j='a'; j<'k'; ++j)
            names.pb(string(1,i)+string(1,j));
    while(names.size()>n) names.pop_back();
    for(int i=k-1; i<n; ++i) if(arr[i-k+1]=="NO") names[i]=names[i-k+1];
    for(auto &i : names) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
