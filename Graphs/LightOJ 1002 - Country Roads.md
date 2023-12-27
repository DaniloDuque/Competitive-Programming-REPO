```cpp
#include <bits/stdc++.h>
using namespace std;


int n, V, E, v1, v2, cost, start, cont = 1;
vector<vector<pair<int, int>>> graph;
vector<int> dp;





struct compare{

    bool operator()(const int &p1, const int &p2){return dp[p1] > dp[p2];} 

};


void dijkstra(int start){

    int visits = 0; dp[start] = 0;
    priority_queue<int, vector<int>, compare> pq; pq.push(start);

    while(!pq.empty()){

        int curr = pq.top(); pq.pop();

        for(pair<int, int> neigh: graph[curr])

            if(max(neigh.second, dp[curr]) < dp[neigh.first]){

                dp[neigh.first] = max(neigh.second, dp[curr]);
                pq.push(neigh.first);

            }

    }

}





int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){

        cout<<"Case "<<cont++<<":\n";
        cin>>V>>E;
        graph.assign(V, {}); dp.assign(V, INT_MAX);
        for(int i = 0; i<E; i++){

            cin>>v1>>v2>>cost;
            graph[v1].push_back({v2, cost});
            graph[v2].push_back({v1, cost});

        }cin>>start;
        dijkstra(start);
        for(int i = 0; i<V; i++) (dp[i] != INT_MAX)? cout<<dp[i]<<'\n': cout<<"Impossible\n";


    }return 0;

}
