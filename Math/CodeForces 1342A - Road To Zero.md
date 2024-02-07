```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, x, y, a, b;

signed main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){
        
        cin>>x>>y>>a>>b;
        cout<<(min(x, y)*min(a<<1, b)) + (abs(x-y))*a<<'\n';

    }return 0;

}
