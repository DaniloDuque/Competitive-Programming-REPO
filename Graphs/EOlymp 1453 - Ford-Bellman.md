```cpp

#include <bits/stdc++.h>
using namespace std;



#define duo pair<int, int>
#define vi vector<int>
#define vvi vector<vector<pair<int, int>>>





vi Bellman(vvi &graph){

    vi memo(graph.size(), 1<<30); memo[0] = 0;

    for(int i = 0; i<graph.size()-1; i++)
        for(int u = 0; u<graph.size(); u++)
            for(duo edge: graph[u])
                if(memo[edge.first] > memo[u] + edge.second)
                    memo[edge.first] = memo[u] + edge.second;

    return memo;

}




int main(){

    int n, m, v1, v2, cost;
    cin>>n>>m;
    vvi graph(n);
    for(int i = 0; i<m; ++i){

        cin>>v1>>v2>>cost;
        graph[--v1].push_back({--v2, cost});

    }vi res = Bellman(graph);

    for(int i: res) cout<<((i >= 1<<29)? 30000: i)<<" ";
    cout<<endl;
    return 0;
}
