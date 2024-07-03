```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m, mat[105][105];

int main(){
    
    scanf("%d", &t);
    while(t--){
        
        memset(&mat, -1, sizeof(mat));
        scanf("%d %d", &n, &m);

        for(int i = 1; i<=n; ++i)
            for(int j = 1; j<=m; ++j)
                scanf("%d", &mat[i][j]);

        for(int i = 1; i<=n; ++i)
            for(int j = 1; j<=m; ++j){
                int &p = mat[i][j];
                if(p > mat[i-1][j] && p > mat[i+1][j] && p > mat[i][j-1] && p > mat[i][j+1])
                    p = max({mat[i-1][j], mat[i+1][j], mat[i][j-1], mat[i][j+1]});        
            }

        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j) printf("%d ", mat[i][j]);
            puts("");
        }

    }return 0;

}
