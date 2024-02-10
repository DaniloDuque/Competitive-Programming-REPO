```cpp
#include <bits/stdc++.h>
using namespace std;



#define int long long
int n;
vector<vector<int>> dp;
vector<string> maze;
bitset<10000000> vis;



void fillDP(){

    for(int i = 1; i<n; i++){

        dp[0][i] = (maze[0][i] == '#')? 0: dp[0][i-1];
        dp[i][0] = (maze[i][0] == '#')? 0: dp[i-1][0];

    }for(int i = 1; i<n; ++i)
        for(int j = 1; j<n; ++j)
            dp[i][j] = (maze[i][j] == '#')? 0: (dp[i-1][j] + dp[i][j-1])%((1LL<<31)-1);

}



bool DFS(int i, int j){

    if(i == n-1 && j == n-1) return true;
    if(i < 0 || j < 0 || i == n || j == n || vis.test((i+1)*n + j+1) || maze[i][j] == '#') return false;
    vis.set((i+1)*n + j+1);
    if(DFS(i+1, j) || DFS(i, j+1) || DFS(i-1, j) || DFS(i, j-1)) return true;
    return false;

}


signed main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n; maze.assign(n, ""); dp.assign(n, vector<int>(n, 1));
    for(int i = 0; i<n; i++) cin>>maze[i];

    fillDP();

    if(dp[n-1][n-1]) cout<<dp[n-1][n-1]<<'\n';
    else if(DFS(0, 0)) cout<<"THE GAME IS A LIE\n";
    else cout<<"INCONCEIVABLE\n";
    return 0;

}
