```cpp
#include <bits/stdc++.h>
using namespace std;

int t, l, r, L, R;

int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d %d %d %d", &l, &r, &L, &R);
        int lft = max(L, l), rgt = min(r, R);
        printf("%d\n", (r<L || R<l)? 1 : (l==L && R==r)? r-l : rgt-lft+2-(r==R || l==L));

    }return 0;

}
