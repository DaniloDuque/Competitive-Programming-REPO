```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main(){
    
    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        int rslt = -1;
        for(int i = 0; i<n; ++i){
            scanf("%d", &x);
            if(!(i&1)) rslt = max(rslt, x);
        }
        printf("%d\n", rslt);

    }return 0;

}
