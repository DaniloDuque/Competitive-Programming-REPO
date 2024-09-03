```cpp
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, n, x, y;
int pnts[MAX][2]; 

void solve(){        
    cin>>n;
    ll rslt = 0, sum[2] = {0, 0};
    for(int i = 0; i<=n; ++i) pnts[i][0] = pnts[i][1] = 0;
    for(int i = 0; i<n; ++i) {cin>>x>>y; pnts[x][y]++;}
    for(int i = 0; i<=n; ++i) sum[1]+=pnts[i][1], sum[0]+=pnts[i][0];
    for(int i = 0; i<=n; ++i)
        for(int r = 0; r<2; ++r)
            if(pnts[i][r]) rslt += (pnts[i][!r])*(sum[r]-1) + ((i-1>=0 && i+1<=n)? (pnts[i-1][!r]&&pnts[i+1][!r]) : 0);
    cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
