```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 5e3+20;
int t=1, n, x[MAX], y[MAX];

ll dist(int i, int j){
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]); 
}

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>x[i];
    for(int i = 0; i<n; ++i) cin>>y[i];
    ll r = 0;
    for(int i = 0; i<n; ++i)
        for(int j = i+1; j<n; ++j)
            r = max(r, dist(i, j));
    cout<<r<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
