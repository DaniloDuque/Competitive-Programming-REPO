```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
int mat[151][151];



void getMaxSum(){

    for(int i = 1; i<=(n<<1); i++)
        for(int j = 1; j<=(n<<1); j++)
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];

    int max = INT_MIN;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            for(int k = i; k<(i+n); k++)  
                for(int w = j; w<(j+n); w++)
                    max = std::max(max, mat[k][w] - mat[i-1][w] - mat[k][j-1] + mat[i-1][j-1]);

    cout<<max<<'\n';
}


int main(){

    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++){
                cin>>mat[i][j];
                mat[i + n][j] = mat[i][j + n] = mat[i + n][j + n] = mat[i][j];

            }
 
        getMaxSum();

    }return 0;

}
