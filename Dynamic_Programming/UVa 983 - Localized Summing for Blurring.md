```cpp
#include <bits/stdc++.h>
using namespace std;


#define ll long long int
int n, m;
bool blank = true;

ll mat[1001][1001];


void resultMatrix(){

    ll rslt = 0;
    for(int i = m; i<=n; ++i)
        for(int j = m; j<=n; j++){
            cout<<(mat[i][j] - mat[i-m][j] - mat[i][j-m] + mat[i-m][j-m])<<'\n';
            rslt += mat[i][j] - mat[i-m][j] - mat[i][j-m] + mat[i-m][j-m];
        }

    cout<<rslt<<'\n';

}


int main(){

    ios::sync_with_stdio(false);
    while(cin>>n>>m){

        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++){
                cin>>mat[i][j]; mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }

        if(!blank) cout<<'\n'; blank = false;
        resultMatrix();

    }return 0;

}
