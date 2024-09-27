```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 101;
int t=1, n, arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int max = 0, idx;
    for(int i = 0; i<n; ++i) if(max < arr[i] || max==arr[i]&&!(i&1)) max=arr[i], idx=i;
    cout<<max + ((n%2==0)? n>>1 : (n>>1) + !(idx&1))<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
