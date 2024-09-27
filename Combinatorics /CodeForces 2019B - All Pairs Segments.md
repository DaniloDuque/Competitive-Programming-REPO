```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1; 
ll n, q, k, arr[MAX];
map<ll, ll> pnts;

void solve(){        
    pnts.clear();
    cin>>n>>q;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    for(int i = 0; i<n-1; ++i) pnts[(i+1)*(n-i-1)] += arr[i+1]-arr[i]-1;
    for(int i = 0; i<n; ++i) pnts[i*(n-i) + (n-i-1)]++;
    while(q--){
        cin>>k;
        cout<<pnts[k]<<' ';
    }cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
