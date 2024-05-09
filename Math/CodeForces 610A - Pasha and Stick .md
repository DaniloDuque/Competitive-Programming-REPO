```cpp
#include <bits/stdc++.h>
using namespace std;

long long n;
        
int main(){
    
    scanf("%lld", &n);
    printf("%lld\n", (n&1)? 0 : (n>>2) - !(n%4));
    return 0;

}
