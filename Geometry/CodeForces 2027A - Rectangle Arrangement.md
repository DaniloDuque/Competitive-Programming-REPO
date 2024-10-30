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
const int MAX = 1e2+20, MOD = 1e9+7;
int t=1, n;
pair<int, int> stmp[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>stmp[i].fst>>stmp[i].snd;
    ll rslt = 0, mxW = 0, mxH = 0;
    for(int i = 0; i<n; ++i){
        if(stmp[i].fst > mxW){
            rslt+=2*(stmp[i].fst-mxW);
            mxW=stmp[i].fst;
        }if(stmp[i].snd > mxH){
            rslt+=2*(stmp[i].snd-mxH);
            mxH = stmp[i].snd;
        }
    }cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
