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
int t=1, n, x;
map<ll, ll> cnt;
vec<ll> arr;

ll solve(){        
    cin>>n; cnt.clear();
    cnt[0]=3; cnt[1]=1;
    cnt[2]=2; cnt[3]=1;
    cnt[5]=1;
    arr.resize(n);
    for(auto &i : arr) cin>>i;
    for(int i=0; i<n; ++i) {
        ll x = arr[i];
        if(cnt[x] > 0) cnt[x]--;
        ll sum = cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[5];
        if(sum <= 0) return i+1;
    }if(cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[5] <= 0) return n;
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
