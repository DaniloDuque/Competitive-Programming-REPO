```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int t, n, m, k;
ll mat[102][102];


void maxPlot(){

    int max = 0; ll price = 0;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; ++j)
            for(int q = i; q<=n; q++)
                for(int w = j; w<=m; w++){

                    int currPrice = mat[q][w] - mat[i-1][w] - mat[q][j-1] + mat[i-1][j-1];
                    int currArea = (q-i+1)*(w-j+1);
                    if (max < currArea && k >= currPrice || (max == currArea && currPrice < price)) {
                        max = currArea;
                        price = currPrice;
                    }

                }

    cout<<max<<" "<<price<<'\n';

}


int main(){

    ios::sync_with_stdio(false);
    cin>>t; int Case = 1;
    while(t--){

        cin>>n>>m>>k;
        for(int i = 1; i<=n; ++i)
            for(int j = 1; j<=m; ++j){
                cin>>mat[i][j];
                mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        cout<<"Case #"<<Case++<<": ";
        maxPlot();

    }return 0;

}
