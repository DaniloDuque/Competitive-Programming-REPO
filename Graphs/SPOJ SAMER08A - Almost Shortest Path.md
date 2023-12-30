```cpp
#include<bits/stdc++.h>
using namespace std;



int n, m, s, d, v1, v2, c;
vector<int> dp;
bitset<501> msk;
vector<vector<pair<int, int>>> graph;
vector<int> prevVertex;
unordered_map<int, unordered_map<int, bool>> edges2Avoid;





void eliminateShortestPath(int last, int parent){

    while(parent !=- 1){

        edges2Avoid[parent][last] = true;
        last = parent;
        parent = prevVertex[parent];

    }

}




void findShortestPaths(){

    prevVertex.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq; pq.push({0, s});
    dp.assign(n, INT_MAX); dp[s] = 0;
    msk.reset();

    while(!pq.empty()){

        int curr = pq.top().second; pq.pop();
   
        for(pair<int, int> neigh: graph[curr]){

            if(dp[neigh.first] > dp[curr] + neigh.second){

                dp[neigh.first] = dp[curr] + neigh.second;
                prevVertex[neigh.first] = curr;
                pq.push({dp[neigh.first], neigh.first});
                if(neigh.first == d) edges2Avoid.clear();  //if we found a shorter route, then clear avoidedEdges

            }

            if(neigh.first == d && dp[neigh.first] == dp[curr] + neigh.second) eliminateShortestPath(d, curr); // if we found a optimal route, then eliminate this path

        }
        
    }

}



void dijkstra(){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,s});
    dp.assign(n, INT_MAX); dp[s] = 0;
    msk.reset();

    while(!pq.empty()){

        int curr = pq.top().second; pq.pop();
        msk.set(curr);

        for(pair<int, int> neigh: graph[curr])

            if(!msk.test(neigh.first) && !edges2Avoid[curr][neigh.first] && dp[neigh.first] > dp[curr] + neigh.second){

                dp[neigh.first] = dp[curr] + neigh.second;
                pq.push({dp[neigh.first], neigh.first});


            }
        
    }
}



int main(){

    ios::sync_with_stdio(false);
    while (cin>>n>>m&&n&&m){

        cin>>s>>d;
        graph.assign(n, {});
        for (int i = 0; i < m; i++){

            cin>>v1>>v2>>c;
            graph[v1].push_back({v2, c});

        }findShortestPaths();
        dijkstra();
        cout << ((dp[d] == INT_MAX) ? -1 : dp[d]) << '\n';

    }return 0;

}
