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
vec<ll> gr;

ll solve(){        
    cin>>n>>s; gr.clear();
    for(int i=0; i<n;) {
        ll cur=0;
        for(int j=i; j<n && s[j]==s[i]; ++j) cur++;
        gr.pb(cur);
        i+=cur;
    }s.erase(unique(ALL(s)), s.end());
    ll c = accumulate(ALL(gr), 0) + s.size();
    if(s.size()==1) return c-(s[0]=='0');
    if(s.size()==2) return c-1;
    if(s.size()==3) return c-2;
    return c-2-(s[0]=='0');
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
