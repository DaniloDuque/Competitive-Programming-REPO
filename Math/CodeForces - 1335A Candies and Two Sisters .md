```cpp
#include <bits/stdc++.h>
using namespace std;
 
long t, n;
 
int main(){
 
    scanf("%ld", &t);
    while(t--){
 
        scanf("%ld", &n);
        printf("%ld\n", (n>>1) - !(n&1));
 
    }return 0;
 
}
