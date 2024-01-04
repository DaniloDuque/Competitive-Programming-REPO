```cpp
#include <bits/stdc++.h>
using namespace std;



#define ll long long

int n, a, b, c;
ll cube[21][21][21], sum;
bool blank = true;




ll rangeSum(int x, int y, int z, int i, int j, int k){

    return  - cube[i-1][y][z]
            - cube[x][j-1][z]
            - cube[x][y][k-1]
            + cube[i-1][j-1][z]
            + cube[i-1][y][k-1]
            + cube[x][j-1][k-1]
            - cube[i-1][j-1][k-1];

}


void maxValueHeap(){

    ll max = sum;
    for(int i = 1; i<a; i++)
        for(int j = 1; j<b; ++j)
            for(int k = 1; k<c; k++)
                for(int x = i; x<a; x++)
                    for(int y = j; y<b; y++)
                        for(int z = k; z<c; z++)
                            max = std::max(max, cube[x][y][z] + rangeSum(x, y, z, i, j, k));

    cout<<max<<'\n';                        

}


int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){

        if(!blank) cout<<'\n';

        cin>>a>>b>>c; ++a; ++b; ++c; sum = 0;
        for(int i = 1; i<a; i++)
            for(int j = 1; j<b; j++)
                for(int k = 1; k<c; k++){
                    cin>>cube[i][j][k];
                    sum += cube[i][j][k];
                    cube[i][j][k] -= rangeSum(i, j, k, i, j, k);
                }
        
        maxValueHeap();
        blank = false;

    }return 0;

}
