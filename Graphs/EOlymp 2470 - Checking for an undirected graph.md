```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int n;
bool x;


bool checkUndirected(){

    for(int i = 0; i<n; i++){

        if(graph[i][i]) return false;
        for(int j = i+1; j<n; j++) if(graph[i][j] != graph[j][i]) return false;

    }return true;   

}


int main(){

    ios::sync_with_stdio(false);
    cin>>n; graph.assign(n, {});
    for(int i = 0; i<n*n; i++){

        cin>>x;
        graph[i/n].push_back(x);

    }

    cout<<((checkUndirected())? "YES": "NO")<<'\n';
    return 0;

}
