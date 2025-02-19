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
int t=1, n, arr[MAX];

ll msb(ll n){
    return 63-__builtin_clzll(n);
}

void solve(){        
    cin>>n;
    if(n&1){
        cout<<n<<endl;
        for(int i=2; i<n-2; ++i) cout<<n-1-i<<' ';
        cout<<1<<' '<<n-2<<' '<<n-1<<' '<<n<<endl;
        return;
    }
    if(n==(n&-n)) {
        set<ll> nums;
        arr[n-1]=n;
        arr[n-2]=n-1;
        arr[n-3]=CLEAR(n-1, msb(n-1));
        arr[n-4]=n-2;
        arr[n-5]=n-3;
        for(int i=1; i<6; ++i) nums.insert(arr[n-i]);
        ll b=1;
        for(int i=0; i<n-5; ++i) {
            b+=nums.count(b);
            arr[i]=b++;
        }cout << (1LL << msb(n)) * 2 - 1 << endl;
        for(int i=0; i<n; ++i) cout<<arr[i]<<' '; cout<<endl;
        return;
    }
    arr[n-1]=(1<<msb(n))-1;
    arr[n-2]=n;
    arr[n-3]=n-1;
    ll b=1;
    for(int i=0; i<n-3; ++i) {
        if(i+1 == arr[n-1]) b++;
        arr[i]=b++;
    }cout << (1LL << msb(n)) * 2 - 1 << endl;;
    for(int i=0; i<n; ++i) cout<<arr[i]<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
