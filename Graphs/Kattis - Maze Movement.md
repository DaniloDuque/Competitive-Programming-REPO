```cpp
#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>


int n, s = 0, t = 0;
vi V, parent;
bitset<1000> vis;
vector<vi> G;




int mcd(int a, int b){
    if(!b) return a;
    return mcd(b, a%b);
}



bool existsPath(int s, int t){

    queue<int> bfs; bfs.push(s); vis.set(s);

    while(!bfs.empty()){

        int curr = bfs.front(); bfs.pop();

        for(int i = 0; i<G.size(); ++i)

            if(!vis.test(i) && G[curr][i] > 0){

                parent[i] = curr;
                if(i == t) return true;
                vis.set(i); bfs.push(i);

            }

    }return false;

}




int maxFlow(int s, int t){

    int MaxFlow = 0;
    parent.assign(G.size(), -1);

    while(existsPath(s, t)){   

        int pathMinFlow = INT_MAX;

        for(int v = t; v != s; v = parent[v])   
            pathMinFlow = min(pathMinFlow, G[parent[v]][v]);

        for(int v = t; v != s; v = parent[v]){  

            G[parent[v]][v] -= pathMinFlow;
            G[v][parent[v]] += pathMinFlow;

        }MaxFlow += pathMinFlow;
        vis.reset();

    }return MaxFlow;


}



signed main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n; V.assign(n, 0); 
    G.assign(n, vi(n, 0));

    for(int i = 0; i<n; i++){
        cin>>V[i];
        if(V[s] > V[i]) s = i;
        if(V[t] < V[i]) t = i;
    }

    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            if(mcd(V[i], V[j]) > 1) 
                G[i][j] = G[j][i] = mcd(V[i], V[j]);

    cout<<maxFlow(s, t)<<'\n';
    return 0;

}
