```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, v1, v2, in_deg[10001], out_deg[10001];
vector<vector<int>> G;
vector<int> path;




bool hasEulerianPath(){

    int strtV = 0, endV = 0;

    for(int i = 0; i<n; i++){

        if(abs(in_deg[i] - out_deg[i]) > 1) return false; 

        else if(out_deg[i] - in_deg[i] == 1) strtV++;  

        else if(in_deg[i] - out_deg[i] == 1) endV++;    

    }return !(strtV|endV) || (strtV == 1 && endV == 1);  

}


int startVertex(){

    int strtV = 0;
    for(int i = 0; i<n; ++i){

        if(out_deg[i] - in_deg[i] == 1) return i; 

        if(out_deg[i]) strtV = i;

    }return strtV;

}



void dfs(int curr){

    while(out_deg[curr]){

        int nxt = G[curr].back();
        --out_deg[curr]; G[curr].pop_back(); 
        dfs(nxt);

    }path.push_back(curr);

}




int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);

    while(cin>>n>>m && n){

        G.assign(n, {}); 
        for(int i = 0; i<n; i++) out_deg[i] = in_deg[i] = 0;

        for(int i = 0; i<m; i++){
            cin>>v1>>v2;
            G[v1].push_back(v2);
            out_deg[v1]++; in_deg[v2]++;
        }

        if(!hasEulerianPath()){
            cout<<"Impossible\n";
            continue;

        }dfs(startVertex());

        if(path.size() == m+1){
            for(int i = m; i>=0; i--) cout<<path[i]<<' '; cout<<'\n';
        }else cout<<"Impossible\n";
        path.clear();
        
    }return 0;
    

}
