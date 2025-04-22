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
#define pll pair<ll, ll>
const int MAX = 2e5+20, MOD = 1e9+7;
ll cntS[27], cntT[27];
string s, t;
priority_queue<pll, vec<pll>, function<bool(pll, pll)>> pq([](pll a, pll b) {
    return (a.snd-a.fst)<(b.snd-b.fst);
});

string solve(){        
    cin>>s>>t;
    for(auto &c : s) cntS[c-'a']++;
    for(auto &c : t) cntT[c-'a']++;
    ll in=0;
    for(int i=0; i<27; ++i) in+=(cntS[i]&&cntT[i]);
    if(!in || s.size()<2 || t.size()<2) return "-1";
    for(int c=0; c<27; ++c) {
        if(!cntS[c] || !cntT[c]) continue;
        ll i=1, j=t.size()-2;
        while(i<s.size() && s[i]!=(c+'a')) ++i;
        while(j>-1 && t[j]!=(c+'a')) --j;
        if(i<s.size() && j>-1) pq.push({i, j});
    }
    if(pq.empty()) return "-1";
    auto [l, r] = pq.top(); string rs;
    for(int i=0; i<l; ++i) rs+=s[i];
    for(int i=r; i<t.size(); ++i) rs+=t[i];
    return rs;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
