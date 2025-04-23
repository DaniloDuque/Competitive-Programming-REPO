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
ll n, arr[3] = {18, 21, 25};
priority_queue<ll> pq;

void solve(){        
    cin>>n; pq.push(60);
    ll c=1;
    for(int k=2; k>=0; --k){
        for(int i=0; i<n; ++i) {
            if(pq.top()<arr[k]) pq.push(60), c++;
            ll cur = pq.top(); pq.pop();
            pq.push(cur-arr[k]);
        }
    }cout<<c<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }return 0;
}
