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
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, m, h;
vec<vec<ll>> mat;

ll points(vec<ll> &v) {
    int p = 0;
    for(int i=0; i<v.size() && v[i]<=h; ++i) p++;
    return p;
}

ll penalty(vec<ll> &v) {
    return accumulate(v.begin(), v.begin()+points(v), 0LL);
}

bool cmp(vec<ll> &a, vec<ll> &b) {
    int p1 = points(a), p2 = points(b);
    if(p1!=p2 || p1==0) return p1>p2;
    return penalty(a) < penalty(b);
}

int solve(){        
    cin>>n>>m>>h;
    mat.assign(n, vec<ll>(m, 0LL));
    for(auto &r : mat) for(auto &i : r) cin>>i;
    for(auto &r : mat) sort(ALL(r));
    for(auto &r : mat) partial_sum(ALL(r), r.begin());
    ll pnts = points(mat[0]), pen = penalty(mat[0]);
    sort(ALL(mat), cmp);
    for(int i=0; i<n; ++i) if(pnts==points(mat[i]) && pen==penalty(mat[i])) return i+1;
    return n;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
