```cpp
#include <bits/stdc++.h>
using namespace std;

int t, l, r;

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d%d", &l, &r);
        r -= l;
        int rslt = 0;
        for(int i = 0, j = 1; i<=r; i+=j, j++) rslt++;
        printf("%d\n", rslt);

    }return 0;

}
