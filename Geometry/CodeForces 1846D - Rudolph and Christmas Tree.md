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
ll t=1, n, d, h, arr[MAX];

double area(double b, double h){
    return b*h/2;
}

double solve(){        
    cin>>n>>d>>h;
    for(int i=0; i<n; ++i) cin>>arr[i];
    double r = n*d*h/2.0;
    for(int i=0; i<n-1; ++i) {
        ll del = arr[i]+h-arr[i+1];
        if(del > 0) r-= area(1.0*del*d/h, del);
    }return r;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<setprecision(18)<<solve()<<endl;
    }return 0;
}
