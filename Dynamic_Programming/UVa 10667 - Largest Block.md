```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 10001
int t, s, n, a, b, c, d;

int mat[101][101];



void putBlock(int i, int j, int x, int y){

    for(int k = i; k<=x; k++)
        for(int w = j; w<=y; w++)
            mat[k][w] = -oo;

}



void getMaxBlock(){

    int max = 0;

    for(int i = 1; i<=s; i++)
        for(int j = 1; j<=s; j++)
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
    
    for(int i = 1; i<=s; i++)
        for(int j = 1; j<=s; j++)
            for(int k = i; k<=s; k++)
                for(int w = j; w<=s; w++)
                    max = std::max(max, mat[k][w] - mat[i-1][w] - mat[k][j-1] + mat[i-1][j-1]);
    
    cout<<max<<'\n';

}



int main(){

    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){

        cin>>s>>n;
        for(int i = 1; i<=s; i++)
            for(int j = 1; j<=s; j++)
                mat[i][j] = 1;

        while(n--){

            cin>>a>>b>>c>>d;
            putBlock(a, b, c, d);

        }getMaxBlock();

    }return 0;

}
