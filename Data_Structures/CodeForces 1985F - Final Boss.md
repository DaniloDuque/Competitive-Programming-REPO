```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vec=vector<T>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20;
ll t=1, h, n, a[MAX], c[MAX];
set<pair<ll, ll>> cool;

void solve(){        
    cool.clear();
    cin>>h>>n;
    for(int i = 0; i<n; ++i) cin>>a[i], h-=a[i];
    for(int i = 0; i<n; ++i) cin>>c[i], cool.emplace(c[i], i);
    ll r = 0;
    while(h > 0){
        auto it = cool.begin();
        r = (*it).fst;
        while(it != cool.end() && r == (*it).fst) {
            auto toErase = it++;
            h -= a[(*toErase).snd];
            cool.emplace(r + c[(*toErase).snd], (*toErase).snd);
            cool.erase(toErase); 
        }
    }cout<<r+1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
