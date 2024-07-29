```cpp
#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 20;
int t, n, b[M], a[M];

bool sol(){

    a[0] = b[0];
    for(int i = 1; i<n-1; ++i) a[i] = b[i-1]|b[i];
    a[n-1] = b[n-2];
    for(int i = 0; i<n-1; ++i) if(b[i] != (a[i]&a[i+1])) return 0;
    return 1;

}


int main(){

    scanf("%d", &t);
    while(t--){
        
        scanf("%d", &n);
        for(int i = 0; i<n-1;) scanf("%d", &b[i++]);
        if(sol()) for(int i = 0; i<n;) printf("%d ", a[i++]);
        else printf("-1");
        puts("");

    }return 0;

}
