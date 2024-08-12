```cpp
#include <bits/stdc++.h>
using namespace std;

int t, x, y, k;

int main(){

    scanf("%d", &t);
    while(t--){
        
        scanf("%d %d %d", &x, &y, &k);
        x *= k; y *= k;
        for(int i = max(x, max(1, y));k > 1;--k, ++i){
            printf("%d %d\n", i, i);
            x -= i, y -= i;
        }printf("%d %d\n", x, y);

    }return 0;

}
