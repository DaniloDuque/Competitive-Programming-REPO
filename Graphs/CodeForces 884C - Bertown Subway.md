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
ll n, x;
vec<ll> arr;

struct UnionFind{
    vector<int> uf;
    void init(int n){uf.assign(n, -1);}
    int Find(int i){return (uf[i]==-1)? i : uf[i] = Find(uf[i]);}
    bool Union(int i, int j){
        bool e = Find(i)==Find(j);
        if(!e) uf[Find(i)] = Find(j);
        return e;
    }
};

inline ll sqr(ll x) {return x*x;}

ll solve(){        
    cin>>n; arr.clear();
    UnionFind uf; uf.init(n);
    for(int i=0; i<n; ++i) cin>>x, uf.Union(i, x-1); 
    map<ll, ll> cnt;
    for(int i=0; i<n; ++i) cnt[uf.Find(i)]++;
    for(auto &[_, c]  : cnt) arr.pb(c); 
    sort(ALL(arr));
    if(arr.size()==1) return arr[0]*arr[0];
    ll r = sqr(arr[arr.size()-2]+arr.back());
    arr.pop_back(); arr.pop_back();
    for(auto &i : arr) r+=i*i;
    return r;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
