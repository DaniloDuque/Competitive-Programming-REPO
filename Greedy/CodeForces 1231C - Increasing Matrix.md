```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, mat[501][501];

int sum(){
    int s = 0;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
            s += mat[i][j];
    return s;
}

int valid(){
    
    for(int i = 1; i<n; ++i)
        for(int j = 1; j<m; ++j)
            if(mat[i][j] <= mat[i-1][j] || mat[i][j] <= mat[i][j-1]) return 0;
    
    return 1;

}

int main(){
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
            scanf("%d", &mat[i][j]);

    for(int i = n-2; i; --i)
        for(int j = m-2; j; --j)
            if(!mat[i][j]) mat[i][j] = min(mat[i+1][j], mat[i][j+1]) - 1;  
    
    printf("%d\n", (valid())? sum() : -1);

    return 0;
}
