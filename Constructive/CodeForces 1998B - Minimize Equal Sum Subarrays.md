```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, p[(int)2e5 + 20];

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d", &n);
        for(int i = 0; i<n;) scanf("%d", &p[i++]);
        printf("%d ", p[n-1]);
        for(int i = 0; i<n-1;) printf("%d ", p[i++]);
        puts("");

    }return 0;

}
