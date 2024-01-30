```cpp
#include <bits/stdc++.h>
using namespace std;


#define msk bitset<500>
#define vi vector<int>
#define vvi vector<vi>
msk vis;  
vvi graph;
vvi flowEdges;
vector<vector<int>> adj;



//bfs function

bool existsPath(vvi &graph, vi &prevVertex, int source, int sink){

    queue<int> bfs; bfs.push(source); vis.set(source);

    while(!bfs.empty()){

        int curr = bfs.front(); bfs.pop();

        for(int i: adj[curr]){

            if(!vis.test(i) && graph[curr][i] > 0){

                prevVertex[i] = curr;
                if(i == sink) return true;
                vis.set(i); bfs.push(i);

            }

        }

    }return false;

}   



int maxFlow(vvi &graph, int source, int sink){
    
    int MaxFlow = 0;
    vi prevVertex(graph.size(), -1);

    while(existsPath(graph, prevVertex, source, sink)){      //while there is a path from source to sink

        int pathMinFlow = INT_MAX;

        for(int v = sink; v != source; v = prevVertex[v])    //find the bottleneck value
            pathMinFlow = min(pathMinFlow, graph[prevVertex[v]][v]);

        for(int v = sink; v != source; v = prevVertex[v]){   //augment the path

            flowEdges[prevVertex[v]][v] += pathMinFlow;
            flowEdges[v][prevVertex[v]] -= pathMinFlow;
            graph[prevVertex[v]][v] -= pathMinFlow;
            graph[v][prevVertex[v]] += pathMinFlow;

        }MaxFlow += pathMinFlow;    
        vis.reset();

    }return MaxFlow;


}




int main(){

    ios::sync_with_stdio(0);
    int n, m, v1, v2, source, sink, flow; 
    cin>>n>>m>>source>>sink; // n->amount of vertices   m->amount of edges
    adj.assign(n, {});
    graph.assign(n, vi(n, 0));
    flowEdges.assign(n, vi(n, 0));

    for(int i = 0; i<m; i++){

        cin>>v1>>v2>>flow;   //from v1 to v2 has flow as maximum flow
        graph[v1][v2] = flow;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);

    }int maxF = maxFlow(graph, source, sink);

    int used = 0;
    vector<pair<int, int>> usedEdges;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(flowEdges[i][j] > 0){
                used++;
                usedEdges.push_back({i, j});
            }

    cout<<n<<" "<<maxF<<" "<<used<<'\n';
    for(pair p: usedEdges) cout<<p.first<<" "<<p.second<<" "<<flowEdges[p.first][p.second]<<'\n';
    return 0;

}
