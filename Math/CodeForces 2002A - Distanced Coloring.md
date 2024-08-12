```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;

int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d %d %d", &n, &m, &k);   
        printf("%d\n", min({k*k, n*k, m*k, n*m}));

    }return 0;

}
