```cpp
#include <algorithm>
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
int t=1, rs;
string s;

void solve(){        
    cin>>s; rs = 0; vec<int> r;
    for(int i = s.size()-1; i>=0; --i){
        if(s[i]+rs < '5') r.push_back(s[i]+rs-'0'), rs = 0;
        else r.push_back(-1), rs=1;
    }
    if(rs){
        cout<<1; 
        for(int i = 0; i<s.size(); ++i) cout<<0;
        cout<<endl;
        return;
    }
    reverse(ALL(r)); int i = 0;
    for(; i<s.size() && r[i]!=-1; ++i) cout<<r[i];
    for(; i<s.size(); ++i) cout<<0;
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
