```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, n;
string s[501];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>s[i];
    for(int i = n-1; i>=0; --i) 
        for(int j = 0; j<4; ++j) if(s[i][j]=='#') cout<<j+1<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
