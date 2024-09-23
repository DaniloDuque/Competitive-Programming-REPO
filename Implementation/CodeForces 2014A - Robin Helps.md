```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, n, k, arr[51];

void solve(){        
    cin>>n>>k; 
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int curr = 0, rslt = 0;
    for(int i = 0; i<n; ++i){ 
        if(arr[i] >= k) curr += arr[i];
        if(!arr[i] && curr) curr--, rslt++;
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
