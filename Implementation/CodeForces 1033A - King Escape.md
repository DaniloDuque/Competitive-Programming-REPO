```cpp
#include <bits/stdc++.h>
using namespace std;

int mat[1100][1100], n, ax, ay, bx, by, cx, cy;

bool case1(){
    return (cx > ax && bx < ax) || (cx < ax && bx > ax) || (cy > ay && by < ay) || (cy < ay && by > ay);
}

int main(){
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    for(int i = 0; i<n; ++i) mat[i][ay] = mat[ax][i] = 1;
    mat[ax + 1][ay + 1] = mat[ax + 1][ay - 1] = mat[ax - 1][ay - 1] = mat[ax - 1][ay + 1] = 1; 
    (mat[cx][cy] || case1())? puts("NO") : puts("YES");
    return 0;
}
 
