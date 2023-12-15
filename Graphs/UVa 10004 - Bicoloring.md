```cpp
#include <iostream>
#include <queue>
using namespace std;


#define vi vector<int>
#define vvi vector<vi>





bool isBipartite(vvi &graph, int i){

    vi memo(graph.size(), 0); memo[i] = 1; queue<int> bfs; bfs.push(i);

    while(!bfs.empty()){

        int curr = bfs.front(); bfs.pop();

        for(int neigh: graph[curr]){

            if(memo[neigh] == memo[curr]) return false;

            if(!memo[neigh]){

                bfs.push(neigh);
                memo[neigh] = ~memo[curr];

            }

        }

    }return true;


}





int main(){

    int n, m, v1, v2, ini;
    while(true){

        cin>>n;
        if(!n) break;
        cin>>m; vvi graph(n);
        for(int i = 0; i<m; i++){

            cin>>v1>>v2; ini=v1;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);

        }if(isBipartite(graph, ini)) cout<<"BICOLORABLE.\n";
        else cout<<"NOT BICOLORABLE.\n";

    }
    return 0;
}
