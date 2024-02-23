```cpp
#include <bits/stdc++.h>
using namespace std;

long double x, y;


int main(){

    scanf("%Lf%Lf", &x, &y);
    long double z = x/y;
    z *= (100-y)/(100-x);
    printf("%.15Lf\n", z); 
    return 0;

}
