```cpp
#include <bits/stdc++.h>
using namespace std;


char x;
int n, m;
int mat[1000][26];


int max(int i){

    int mx = 0, index = 0;
    for(int j = 0; j<26; ++j)
        if(mat[i][j] > mx){
            mx = mat[i][j];
            index = j;
        }

    return index;

}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j){
            cin>>x;
            ++mat[j][x-97];
        }
    for(int i = 0; i<m; ++i) cout<<(char)(max(i) + 97);
    cout<<'\n';
    return 0;

}
