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
const int MAX = 1e2+20;
int t=1, n, r, x;

void solve(){        
    cin>>n>>r;
    int happy = 0, odd = 0;
    for(int i = 0; i<n; ++i){
        cin>>x;
        happy += x-(x&1), r-=(x>>1);
        odd += (x&1);
    }if(r>=odd) cout<<happy+odd;
    else cout<<happy + r*2 - odd;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
