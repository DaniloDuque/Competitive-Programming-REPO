```cpp
#include <bits/stdc++.h>
using namespace std;

 
int t, a, b, l;
set<int> S;


int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d %d %d", &a, &b, &l);
        int sum = 0; S.clear();

        for(int x = 1; (x <= l) && !(l%x); x *= a)
            for(int y = x; (y <= l) && !(l%y); y *= b)
                if(!(l%y)){
                    sum += !S.count(l/y);
                    S.insert(l/y);
                }

        printf("%d\n", sum);

    }return 0;

}
