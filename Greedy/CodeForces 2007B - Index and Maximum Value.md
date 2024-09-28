```cpp
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
ll t=1, n, m, l, r, arr[MAX];
char op;

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int max = *max_element(arr, arr+n);
    while(m--){
        cin>>op>>l>>r;
        if(max >= l && max <= r) max += (op=='+')? 1 : -1;
        cout<<max<<' ';
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
