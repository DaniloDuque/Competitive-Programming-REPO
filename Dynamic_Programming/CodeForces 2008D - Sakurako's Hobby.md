```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+20;
int t, n, arr[MAX], dp[MAX], who[MAX];
string s;
bitset<MAX> vis;

int F(int i, int w){
    if(vis.test(i)) return 0;
    vis.set(i);
    who[i] = w;
    return (s[i-1]=='0') + F(arr[i], w); 
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
    
        cin>>n;
        for(int i = 1; i<=n; ++i) cin>>arr[i], dp[i] = -1, who[i] = 0;
        cin>>s;
        for(int i = 1; i<=n; ++i) if(who[i]) dp[i] = dp[who[i]]; else vis.reset(), dp[i] = F(i, i);
        for(int i = 1; i<=n; ++i) cout<<dp[i]<<' ';
        cout<<'\n';

    }return 0;

}
