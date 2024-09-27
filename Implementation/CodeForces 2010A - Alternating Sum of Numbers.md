```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, n, x;

void solve(){        
    cin>>n;
    int sum = 0;
    for(int i = 0; i<n; ++i) cin>>x, sum -= (i&1)? x : -x;
    cout<<sum<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
