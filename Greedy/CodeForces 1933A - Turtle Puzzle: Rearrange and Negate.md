```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, a_i, sum;


int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        sum = 0;
        while(n--){

            cin>>a_i;
            sum += abs(a_i);

        }printf("%d\n", sum);

    }return 0;

}
