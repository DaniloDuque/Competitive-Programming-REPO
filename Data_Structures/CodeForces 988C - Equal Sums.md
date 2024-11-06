```cpp
#include <bits/stdc++.h>
#include <numeric>
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
int t=1, k, n;
vec<vec<int>> seq;
map<ll, pair<int, int>> sums;

void solve(){        
    cin>>k; seq.resize(k); sums.clear();
    for(auto &r : seq){
        cin>>n; r.resize(n);
        for(auto &j : r) cin>>j;
    }
    for(int i = 0; i<k; ++i){
        ll sum = accumulate(ALL(seq[i]), 0LL);
        for(int j = 0; j<seq[i].size(); ++j){
            if(sums.count(sum-seq[i][j]) && sums[sum-seq[i][j]].fst != i+1) {
                cout<<"YES\n";
                cout<<sums[sum-seq[i][j]].fst<<' '<<sums[sum-seq[i][j]].snd<<'\n';
                cout<<i+1<<' '<<j+1<<'\n';
                return;
            }
            sums[sum-seq[i][j]] = {i+1, j+1};
        }
    }cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
