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
int t=1, n, k, c;
map<int, int> mp;

void solve(){        
    cin>>n>>k; mp.clear();
    for(int i=0; i<n; ++i) cin>>c, mp[c]++;
    int r = 0;
    for(auto &x : mp){
        int &cnt = mp[k-x.fst];
        if(x.snd && cnt && x.fst != k-x.fst){
            int cur = min(x.snd, cnt);
            r+=cur; x.snd=0, cnt=0;
        }else if(x.snd && cnt) r+=x.snd>>1, x.snd=0;
    }cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
