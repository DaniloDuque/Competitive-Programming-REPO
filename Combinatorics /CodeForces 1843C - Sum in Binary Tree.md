```cpp
#include <bits/stdc++.h>
using namespace std;

long long t, n, sum; 

signed main(){

    scanf("%lld", &t);
    while(t--){

        scanf("%lld", &n); sum = 0;
        for(;n; sum += n, n>>=1);
        printf("%lld\n", sum);

    }return 0;

}
