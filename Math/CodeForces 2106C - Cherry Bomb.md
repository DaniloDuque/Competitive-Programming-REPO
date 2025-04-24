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
ll n, k, a[MAX], b[MAX];

ll Case(){
    return *min_element(a, a+n)+k-*max_element(a, a+n)+1;
}

ll solve(){        
    cin>>n>>k;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    if(accumulate(b, b+n, 0) == -n) return max(0LL, Case());
    ll cur=-1;
    for(int i=0; i<n; ++i) {
        if(b[i]==-1) continue;
        if(cur>-1 && a[i]+b[i] != cur) return 0;
        cur=a[i]+b[i];
    }
    for(int i=0; i<n; ++i) if(cur>-1 && (cur<a[i] || a[i]+k < cur)) return 0;
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
