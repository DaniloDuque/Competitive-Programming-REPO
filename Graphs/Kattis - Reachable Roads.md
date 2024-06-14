```cpp
#include <bits/stdc++.h>
using namespace std;

int c, t, n, m, x, y, uf[1001];

int Find(int i){
    return uf[i] == i ? i : uf[i] = Find(uf[i]);
}

void Union(int i, int j){        
    int x = Find(i), y = Find(j);
    if(x == y) return;
    uf[y] = x;
}

int main(){
    
    scanf("%d", &t);
    while(t--){
        
        scanf("%d %d", &n, &m);
        iota(uf, uf+n, 0);
        while(m--){
            scanf("%d %d", &x, &y);
            Union(x, y);
        }c = 0;
        for(int i = 0; i<n; ++i) c += uf[i] == i;
        printf("%d\n", c-1);

    }return 0; 

}
