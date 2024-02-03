```cpp
#include <bits/stdc++.h>
using namespace std;



bitset<100001> vis;
int n, m, v1, v2, idx;
vector<vector<int>> G;
vector<int> topSort, dp, path;



void TopSort(int start){

    if(vis.test(start)) return;
    vis.set(start);
    for(int &neigh : G[start])
        if(!vis.test(neigh)) TopSort(neigh);
    topSort.push_back(start);

}

void TopologicalSort() {
    for (int i = 0; i < n; i++)
        if (!vis.test(i))
            TopSort(i);
}






int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m; G.assign(n, {}); dp.assign(n, 1);

    while (m--){
        cin>> v1 >> v2;
        G[v1 - 1].push_back(v2 - 1);

    }TopologicalSort();  //stores topologicalSort on 'topSort'
    
    for(int &i : topSort)
        for(int &neigh : G[i])
            dp[i] = max(dp[i], 1 + dp[neigh]);

    for(int i = 0; i < n; i++) if(dp[topSort[idx]] < dp[topSort[i]]) idx = i;

    idx = topSort[idx];
    while(dp[idx] != 1){
        path.push_back(idx);
        for(int &neigh : G[idx])
            if (dp[idx] == dp[neigh] + 1){
                idx = neigh;
                break;
            }
        
    }path.push_back(idx);
    cout<<path.size()<<'\n';
    for(int i: path) cout<<i+1<<' '; cout<<'\n';
    return 0;

}
