```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, v1, v2, c;
vector<vector<int>> graph;
vector<int> from, dp;


#define INF 999999999



int BellmanFord(int start, int end) {
    
    dp.assign(n, INF); dp[start] = 0;
    from.assign(n, 0);
    
    for (int i = 0; i < n - 1; ++i)
        for (int u = 0; u < n; ++u)
            for (int j = 0; j < n; j++)
                if (dp[j] > dp[u] + graph[u][j]){
                    dp[j] = dp[u] + graph[u][j];
                    from[j] = u;
                }

    return dp[end];
    
}



int main(){

    ios::sync_with_stdio(false);
    while(cin>>n && n){

        cin>>m; graph.assign(n, vector<int>(n, INF));
        while(m--){

            cin>>v1>>v2>>c;
            graph[--v1][--v2] = c;
            graph[v2][v1] = c;

        }int first = BellmanFord(0, n-1);
        if(first >= INF) cout<<"Back to jail\n";
        else{

            for(int end = n-1; from[end] != end; end = from[end]){

                graph[end][from[end]] = INF;
                graph[from[end]][end] *= -1;

            }int second = BellmanFord(n-1, 0);
            (second >= INF)? cout<<"Back to jail\n": cout<<first+second<<'\n';

        }  
        
    }return 0;

}
