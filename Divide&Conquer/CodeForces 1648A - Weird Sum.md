```cpp
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
#define pi pair<ll, ll>
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, m, x;
map<int, vec<ll>> clrsX, clrsY;

ll sum(vec<ll> &v){
    ll rslt = 0, sum = 0;
    sort(ALL(v)); 
    for(int i = 0; i<v.size(); ++i) rslt += v[i]*i-sum, sum+=v[i];
    return rslt;
}

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) 
        for(int j = 0; j<m; ++j){
            cin>>x;
            clrsX[x].push_back(i);
            clrsY[x].push_back(j);
        }
    ll rslt = 0;
    for(auto &p : clrsX) rslt += sum(p.snd);
    for(auto &p : clrsY) rslt += sum(p.snd);
    cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
