```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, n, x, y, z; 

signed main(){
    
    scanf("%lld", &t);
    while(t--){
    
        scanf("%lld %lld %lld", &n, &x, &y);
        int sum = 0, p = y&1;
        for(int i = 0; i<n; ++i) scanf("%lld", &z), sum+=z;
        if(sum&1) p = !p;
        puts((p == x%2)? "Alice" : "Bob");

    }return 0;

}
