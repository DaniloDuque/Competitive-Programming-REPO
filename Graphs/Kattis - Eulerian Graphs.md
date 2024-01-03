```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, v1, v2;

vector<vector<int>> graph;
vector<int> in_deg, out_deg;


void countDegrees(){

    in_deg.assign(n, 0); out_deg.assign(n, 0);

    for(int i = 0; i<n; i++){

        out_deg[i] += graph[i].size();
        for(int j: graph[i]) in_deg[j]++;        
    
    }

}



void hasEulerianPath(){

    int strtV = 0, endV = 0, start, end;

    for(int i = 0; i<n; ++i){

        if(abs(in_deg[i]-out_deg[i]) > 1){
            
            cout<<"no\n";
            return;

        }else if(out_deg[i] - in_deg[i] == 1){
            
            start = i;
            strtV++;
        
        }else if(in_deg[i] - out_deg[i] == 1){
            
            endV++;
            end = i;

        }

    }if(!strtV && !endV) cout<<"anywhere\n";

    else if(strtV == 1 && endV == 1) cout<<start+1<<" "<<end+1<<'\n';

    else cout<<"no\n";
    

}


int main(){

    ios::sync_with_stdio(false);
    cin>>n>>m;
    graph.assign(n, {});

    while(m--){

        cin>>v1>>v2;
        graph[--v1].push_back(--v2);

    }countDegrees();
    hasEulerianPath();
    return 0;

}
