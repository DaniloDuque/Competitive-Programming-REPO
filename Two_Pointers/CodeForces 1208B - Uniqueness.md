```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define slice(a, n) ranges::subrange(a, a+n)
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &ee:a) cout<<ee<<' ';cout<<endl;
#define ALL(v) (v).begin(), (v).end()
#define ALLR(a) (a), (a+n)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e3+20, MOD = 1e9+7;
ll n, x, arr[MAX];
map<ll, ll> cnt;
set<ll> st;

ll solve(){        
    cin>>n; 
    for(auto &i : slice(arr, n)) cin>>i, cnt[i]++, st.insert(i);
    vec<ll> v;
    for(auto &[x, y] : cnt) if(y<2) v.pb(x);
    for(auto &i : v) cnt.erase(i), st.erase(i);
    if(st.empty()) return 0;
    int r = n;
    for(int i=0; i<n; ++i) {
        map<ll, ll> cur(ALL(cnt));
        set<ll> s(ALL(st));
        if(!s.count(arr[i])) continue;
        for(int j=i; j<n; ++j) {
            cur[arr[j]]--;
            if(cur[arr[j]]<2) s.erase(arr[j]);
            if(s.size()) continue;
            r=min(r, j-i+1);
            break;
        }
    }return r;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    while(T--){
        cout<<solve()<<endl;
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
