```cpp
#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int main(){
    
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        
        scanf("%d %d", &x, &y);
        puts(y > -2? "YES" : "NO"); 

    }return 0;

}
