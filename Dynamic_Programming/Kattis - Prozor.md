```cpp
#include <bits/stdc++.h>
using namespace std;


char c;
int h, w, k;
vector<vector<char>> window;
int dp[101][101];




void accumulateDP(){

    for(int i = 1; i<h; i++) dp[i][0] += dp[i-1][0];
    for(int i = 1; i<w; i++) dp[0][i] += dp[0][i-1];
    for(int i = 1; i<h; i++)
        for(int j = 1; j<w; j++) dp[i][j] += dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];

}




int howManyFlies(int i, int j, int bttmX, int bttmY){

    if(bttmX+1 >= h || bttmY+1 >= w) return 0;
    return dp[bttmX][bttmY] + dp[i-1][j-1] - dp[bttmX][j-1] - dp[i-1][bttmY];

}





void maxFlies(){

    int x, y, maX = 0;
    for(int i = 0; i+k-1<h; i++){
        for(int j = 0; j+k-1<w; j++){

            int flies = howManyFlies(i+1, j+1, i + k - 2, j + k - 2);
            if(maX < flies){
                maX = flies; x = i; y = j;
            }

        }

    }cout<<maX<<'\n';
    window[x][y] = window[x][y+k-1] = window[x+k-1][y] = window[x+k-1][y+k-1] = '+';
    for(int i = x+1; i<x+k-1; i++) window[i][y] = window[i][y+k-1] = '|';
    for(int i = y+1; i<y+k-1; i++) window[x][i] = window[x+k-1][i] = '-';
    for(vector<char> row: window){
        for(char c: row) cout<<c;
        cout<<'\n';
    }


}









int main(){

    ios::sync_with_stdio(false);
    cin>>h>>w>>k; window.assign(h, vector<char>(0));
    for(int i = 0; i<h; i++)
        for(int j = 0; j<w; j++){

            cin>>c;
            window[i].push_back(c);
            dp[i][j] = (c=='*');

        }
    
    accumulateDP();
    maxFlies();
    return 0;

}
