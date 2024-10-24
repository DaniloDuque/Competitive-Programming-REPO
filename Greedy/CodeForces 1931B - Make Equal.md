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

bool solve(){        
    cin>>n;
    ll sum = 0, def = 0;
    for(int i = 0; i<n; ++i) {cin>>arr[i]; sum+=arr[i];}
    if(n==1) return 1;
    ll obj = sum/n;
    for(int i = n-1; i>=0; --i){
        if(arr[i]-obj > def) return 0;
        if(arr[i]<obj) def += obj-arr[i];
        else def -= arr[i]-obj;
    }return !def;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<'\n';
    }return 0;
}
