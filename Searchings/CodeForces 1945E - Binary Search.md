```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20;
int t=1, n, x, arr[MAX];

int search(int l, int r, int x){
    while(r-l > 1){
        int m = (l+r)>>1;
        if(arr[m]<=x) l=m;
        else r=m;
    }return l;
}

void solve(){        
    cin>>n>>x;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int i = 0;
    while(arr[i]!=x) ++i;
    cout<<1<<endl;
    cout<<i+1<<' '<<search(0, n, x)+1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
