```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[(int)2e5 + 20];

int main(){

    scanf("%d %d", &n, &m);
    for(int i = 0; i<n;) scanf("%d", &arr[i++]);
    int c = 0;
    for(int i = 0; i<n-1; ++i){
        c += arr[i];
        printf("%d ", c/m);
        if(c >= m) c %= m;
    }printf("%d\n", (c + arr[n-1])/m);
    return 0;

}
