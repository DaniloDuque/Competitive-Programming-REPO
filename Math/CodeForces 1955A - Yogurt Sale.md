```cpp
#include <bits/stdc++.h>

int main(){

    int t, n, a, b;
    scanf("%d", &t);
    while(t--){

        scanf("%d %d %d", &n, &a, &b);
        printf("%d\n", std::min((n>>1)*b + a*(n&1), n*a));

    }return 0;

}
