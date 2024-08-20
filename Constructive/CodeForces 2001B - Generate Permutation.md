```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d", &n);
        if(!(n&1)) puts("-1");
        else{
            for(int i = n; i>(n>>1)+1; --i) printf("%d ", i);
            for(int i = 1; i<=(n>>1)+1; ++i) printf("%d ", i); 
            puts("");
        }
        
    }return 0;

}
