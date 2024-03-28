```cpp
#include <iostream> 

int main(){

    int n;
    scanf("%d", &n);
    if(n < 100) puts("99");
    else printf("%d\n", (n%100 == 49)? n + 50: (n%100 < 49)? n - n%100 - 1: n + (100 - n%100) - 1);
    return 0;   

}
