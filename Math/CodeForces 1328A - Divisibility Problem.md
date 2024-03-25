```cpp
#include <bits/stdc++.h>
using namespace std;


long t, a, b;


int main(){

    scanf("%ld", &t);
    while(t--){

        scanf("%ld %ld", &a, &b);
        printf("%ld\n", (a%b)? b * (a/b + 1) - a: 0);

    }return 0;

}
