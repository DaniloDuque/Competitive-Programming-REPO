```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, v1, v2, w, uf[20000], MSTcost;
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> MST;



int Find(int node){

    if(uf[node] == node) return node;       
    return uf[node] = Find(uf[node]);

}



bool Kruskal(){

    MSTcost = 0;
    MST.clear();
    sort(edges.begin(), edges.end());

    for(auto edge: edges){

        int parU = Find(get<1>(edge));
        int parV = Find(get<2>(edge));
        if(parU != parV){

            MST.emplace_back(get<1>(edge), get<2>(edge));
            MSTcost += get<0>(edge);
            uf[parU] = parV;

        }

    }for(int i = 1; i<n; i++) if(Find(i) != Find(i-1)) return false;
    return true;

}






int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    while(cin>>n>>m && n){

        iota(uf, uf+n, 0);
        edges.clear();

        while(m--){
            cin>>v1>>v2>>w;
            edges.emplace_back(w, v1, v2);
            edges.emplace_back(w, v2, v1);
        }

        if(!Kruskal()) cout<<"Impossible\n";
        else{
            sort(MST.begin(), MST.end());
            cout<<MSTcost<<'\n';
            for(auto e: MST) cout<<e.first<<" "<<e.second<<'\n';
        }

    }return 0;

}
