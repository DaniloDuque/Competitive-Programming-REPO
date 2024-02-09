```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, v1, v2;
bitset<200000> vis;
vector<vector<int>> G;


void DFS(int i){

    if(vis.test(i)) return;
    vis.set(i);
    for(int &j: G[i]) DFS(j);

}


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m; G.assign(n, {});
    while(m--){

        cin>>v1>>v2;
        G[--v1].push_back(--v2);
        G[v2].push_back(v1);

    }DFS(0);

    int c = 0;
    for(int i = 0; i<n; i++) 
        if(!vis.test(i)){
            cout<<i+1<<'\n';
            c++;
        }
    if(!c) cout<<"Connected\n";
    return 0;

}
