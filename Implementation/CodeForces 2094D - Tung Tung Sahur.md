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
string p, s;
vec<ll> cntP, cntS;

bool solve(){        
    cin>>p>>s;
    cntP.clear(), cntS.clear();
    for(int i=0; i<p.size();) {
        ll cur=1;
        for(int j=i+1; j<p.size() && p[j]==p[i]; ++j) cur++;
        cntP.pb(cur);
        i+=cur;
    }
    for(int i=0; i<s.size();) {
        ll cur=1;
        for(int j=i+1; j<s.size() && s[j]==s[i]; ++j) cur++;
        cntS.pb(cur);
        i+=cur;
    }
    s.erase(unique(ALL(s)), s.end());
    p.erase(unique(ALL(p)), p.end());
    if(p != s) return 0;
    for(int i=0; i<p.size(); ++i) if(cntS[i] < cntP[i] || cntS[i] > 2*cntP[i]) return 0;
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
