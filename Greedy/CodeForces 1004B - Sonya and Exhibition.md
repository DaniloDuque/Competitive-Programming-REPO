```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, l, r;

int main(){
    scanf("%d %d", &n, &m);
    while(m--) scanf("%d %d", &l, &r);
    for(int i = 0; i<n; ++i) printf((i&1)? "1" : "0");
    puts("");
    return 0;
}
