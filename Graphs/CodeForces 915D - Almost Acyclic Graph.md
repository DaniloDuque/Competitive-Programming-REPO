```cpp
#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define vvi vector<vi>


int n, m, v1, v2;
vvi graph;
vi in_deg, aux_deg;



//use kahns algorithm to find cycles  O(n)
bool notAcyclic(){

    int visited = 0;
    queue<int> queue;

    for(int i = 0; i<n; i++) if(!aux_deg[i]) queue.push(i);

    while(!queue.empty()){

        int curr = queue.front(); queue.pop();

        visited++;

        for(int nxt: graph[curr]) if(!(--aux_deg[nxt])) queue.push(nxt);

    }return visited == n;

}



bool possibleAcyclic(){

    for(int i = 0; i<n; i++)    //for every vertex that has incoming edges, try removing one
        
        if(in_deg[i] >= 1){
            
            aux_deg.assign(in_deg.begin(), in_deg.end()); aux_deg[i]--;
            if(notAcyclic()) return true;

        }
    
    return false;

}




int main(){

    ios::sync_with_stdio(false);
    cin>>n>>m;
    in_deg.assign(n, 0);
    aux_deg.assign(n, 0);
    graph.assign(n, {});

    while(m--){

        cin>>v1>>v2;
        graph[--v1].push_back(--v2);
        ++in_deg[v2];
        ++aux_deg[v2];

    }cout<<((possibleAcyclic())? "YES\n": "NO\n");
    return 0;

}
