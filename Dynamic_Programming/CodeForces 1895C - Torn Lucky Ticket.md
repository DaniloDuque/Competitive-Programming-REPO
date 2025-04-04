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
ll n, dp[6][46];
vec<string> arr;

void solve() {
    cin>>n; arr.resize(n);
    memset(dp, 0, sizeof(dp));
    for(auto &i : arr) {
        cin>>i;
        ll sum=0;
        for(auto &c : i) sum+=c-'0';
        dp[i.size()][sum]++;
    }
    ll rs = 0;
    for(auto &s : arr) {
        ll sz = s.size();
        for(int j=0; j<=sz; ++j) {
            ll tot=sz+j;
            if(tot&1) continue;
            ll sumL=0, sumR=0;
            for(int k=0; k<tot/2 && k<sz; ++k) sumL+=s[k]-'0';
            for(int k=tot/2; k<sz; ++k) sumR+=s[k]-'0';
            if(sumL-sumR >= 0) rs+=dp[j][sumL-sumR];
            if(j<sz) {  
                sumL=sumR=0;
                for(int k=sz-tot/2; k<sz; ++k) sumL+=s[k]-'0';
                for(int k=0; k<sz-tot/2; ++k) sumR+=s[k]-'0';
                if(sumL-sumR >= 0) rs+=dp[j][sumL-sumR];
            }
        }
    }cout<<rs<<endl;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
