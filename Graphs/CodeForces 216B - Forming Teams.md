```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> G[102];
bitset<102> vis;

int dfs(int i){
    if(vis.test(i)) return 0;
    vis.set(i);
    int r = 1;
    for(int &j : G[i]) r+=dfs(j);
    return r;
}

int main(){

    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &u, &v);
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }int c = 0, r = 0;
    for(int i = 0; i<n; ++i) if(G[i].size() <= 1) c+=dfs(i)&1;
    for(int i = 0; i<n; ++i) r+=dfs(i)&1;
    printf("%d\n", r + (c&1));
    return 0;

}
