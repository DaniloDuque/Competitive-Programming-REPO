```cpp
#include <bits/stdc++.h>
using namespace std;


char digits[10];


bool diffDigits(int n){

    memset(digits, 0, sizeof(digits));
    for(;n;n/=10) ++digits[n%10];
    for(int i = 0; i<10; ++i) if(digits[i] > 1) return 0;
    return 1;

}


int main(){

    int n; scanf("%d", &n);
    while(!diffDigits(++n));
    printf("%d\n", n);
    return 0;

}
