```cpp
#include <bits/stdc++.h>
using namespace std;

#define dist(a, b, x, y) (sqrt(pow(a-x, 2) + pow(b-y, 2)))
double x, y, x_1, y_1, x_2, y_2;


int main(){

    scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &x_1, &y_1, &x_2, &y_2);
    printf("%lf\n", (x >= x_2 && y >= y_2)? dist(x, y, x_2, y_2): 
                    (x >= x_2 && y <= y_1)? dist(x, y, x_2, y_1): 
                    (x >= x_2)? x - x_2:
                    (x <= x_1 && y <= y_1)? dist(x, y, x_1, y_1):
                    (x <= x_1 && y >= y_2)? dist(x, y, x_1, y_2):
                    (x <= x_1)? x_1 - x:
                    (y >= y_2)? y - y_2: y_1 - y);
    return 0;

}
