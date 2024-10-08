```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, x, y;

void solve(){        
    cin>>x>>y;
    int r = 0;
    while((x&1) == (y&1)){
        r++;
        x>>=1; y>>=1;
    }cout<<(1<<r)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}