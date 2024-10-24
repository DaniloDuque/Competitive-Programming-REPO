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
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, n, arr[MAX];
set<ll> sums;

int Kadane(){
    ll s = 0, o1 = 0; sums.insert(0);
    for(int i = 0; i<n; ++i){
        s+=arr[i];
        if(!sums.count(s)) {sums.insert(s); continue;}
        else ++o1, sums.clear(), s=0, sums.insert(0);
    }return o1;
}

void solve(){        
    cin>>n; sums.clear();
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int count0 = 0;
    for(int i = 0; i<n; ++i) count0 += !arr[i];
    cout<<max(count0, Kadane())<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
