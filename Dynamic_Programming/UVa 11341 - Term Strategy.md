```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 100001
int t, n, m, mat[11][101], dp[11][101][101];




int maxGPA(int i, int j, int h){

    if(h < 0) return -oo;
    if(i == n) return 0;

    int &curr = dp[i][j][h];
    if(curr != -1) return curr;
    curr = -oo;

    if(mat[i][j] > 4) curr = max(curr, maxGPA(i+1, 0, h-j-1) + mat[i][j]);
    if(j < h) curr = max(curr, maxGPA(i, j+1, h));
    return curr;

}



int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d %d", &n, &m);
        memset(dp, -1, sizeof(dp));
    
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                scanf("%d", &mat[i][j]);

        double rslt = maxGPA(0, 0, m);

        (rslt < 0)? puts("Peter, you shouldn\'t have played billiard that much."):
                    printf("Maximal possible average mark - %.2f.\n", round((rslt/n)*100)/100);


    }return 0;

}
