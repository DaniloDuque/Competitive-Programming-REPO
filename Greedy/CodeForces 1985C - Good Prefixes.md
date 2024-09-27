```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
ll t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    ll rslt = 0, sum = 0, max = -1;
    for(int i = 0; i<n; ++i){
        max = std::max(max, arr[i]);
        sum += arr[i];
        rslt += (max<<1==sum);
    }cout<<rslt<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
