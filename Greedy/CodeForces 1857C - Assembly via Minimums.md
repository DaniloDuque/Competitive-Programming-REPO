```cpp
#include <bits/stdc++.h>
#include <set>
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
const int MAX = 2e6+20, MOD = 1e9+7;
ll t=1, n, arr[MAX];
map<ll, ll> cnt;

void solve(){        
    cin>>n; cnt.clear(); 
    ll c = n*(n-1)/2;
    for(int i = 0; i<c; ++i) cin>>arr[i], cnt[arr[i]]++;
    vec<ll> r; ll cur = n-1;
    for(auto &p : cnt){
        while(p.snd && p.snd >= cur){
            r.push_back(p.fst);
            p.snd-=cur;
            cur--;
        }
    }for(int i = r.size(); i<n; ++i) r.push_back(MOD-7);
    for(ll &i : r) cout<<i<<' '; cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
