```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, MOD = 1e9+7;
ll n, k, arr[MAX];

bool solve(){        
    cin>>n>>k;
    for(auto &i : span(arr, n)) cin>>i;
    int i=0, j=n-1;
    for(;i<n && arr[i]==0; ++i);
    for(;j>=0 && arr[j]==0; --j);
    if(i==n) return 1;
    return (j-i+1) <= k; 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
