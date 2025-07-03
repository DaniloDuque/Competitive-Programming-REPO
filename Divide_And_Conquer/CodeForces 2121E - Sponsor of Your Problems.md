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
string a, b;

ll dow(int i) {
    if(i==a.size()) return 0;
    if(a[i]=='9') return 1+(b[i]=='9')+dow(i+1); 
    return 0;
}

ll up(int i) {    
    if(i==a.size()) return 0;
    if(b[i]=='0') return 1+(a[i]=='0')+up(i+1);
    return 0;
}

ll bt(int i) {
    if(i==a.size()) return 0;
    if(a[i]==b[i]) return 2+bt(i+1);
    if(a[i]==b[i]-1) return 1+min(up(i+1), dow(i+1));
    return 0;
}

void solve(){        
    cin>>a>>b;
    cout<<(bt(0))<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
