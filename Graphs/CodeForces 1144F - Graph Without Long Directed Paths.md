```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<vector<int>> G;
int memo[(int) 2e5 + 20];
vector<pair<int, int>> edges;

bool color(int i){
    
    memo[i] = 1; queue<int> bfs; bfs.push(i);
    while(!bfs.empty()){
        int curr = bfs.front(); bfs.pop();
        for(int neigh: G[curr]){
            if(memo[neigh] == memo[curr]) return 0;
            if(!memo[neigh]){
                bfs.push(neigh);
                memo[neigh] = ~memo[curr];
            }
        }

    }return 1;
    
}


int main(){
    
    scanf("%d %d", &n, &m);
    G.assign(n, {});
    while(m--){
        scanf("%d %d", &u, &v);
        G[--u].push_back(--v);
        G[v].push_back(u);
        edges.emplace_back(u, v);
    }
    if(color(0)){
        puts("YES");
        for(auto &p : edges) printf("%d", (memo[p.first] == 1)? 1 : 0);
        puts("");
    }else puts("NO");
    return 0;
}

