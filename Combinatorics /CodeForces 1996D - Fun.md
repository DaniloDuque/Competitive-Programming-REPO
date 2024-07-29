```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, x, n;

signed main(){
    
    scanf("%lld", &t);
    while(t--){
    
        scanf("%lld %lld", &n, &x);
        int rslt = 0;
        for(int i = 1; i <= min(n>>1, x); ++i)
            for(int j = 1; i*j + i + j <= n && i + j < x; ++j) rslt += min((n - i*j)/(i + j), x - i - j);
        printf("%lld\n", rslt);
    
    }return 0;

}
