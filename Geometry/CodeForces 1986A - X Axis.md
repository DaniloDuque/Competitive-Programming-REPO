```cpp
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


int t, points[3], a;

int main(){
    
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &points[0], &points[1], &points[2]);
        sort(points, points+3);
        printf("%d\n", abs(points[0] - points[1]) + abs(points[2] - points[1]));

    }return 0;

}
