```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, a_i, sum, arr[3];


int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        sum = arr[0] = arr[1] = arr[2] = 0;
        while(n--){

            cin>>a_i; a_i %= 3;
            ++arr[a_i]; sum = (sum+a_i)%3;

        }printf("%d\n", (!sum)? 0: (sum == 2 || (sum == 1 && arr[1]))? 1: 2);
        

    }return 0;

}
