```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
ll t=1, x, y, k;

ll ceil(int i, int j){
    return i/j + !!(i%j);
}

void solve(){        
    cin>>x>>y>>k; 
    cout<<((ceil(y, k)>=ceil(x, k))? 2*ceil(y, k) : 2*ceil(x, k) - 1)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
