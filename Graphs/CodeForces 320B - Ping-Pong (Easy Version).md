```cpp
#include <bits/stdc++.h>
using namespace std;


int n, x, a, b, G[101][101];
vector<pair<int, int>> arr;
bitset<101> vis;




bool connected(int i, int j){
    return (arr[i].first > arr[j].first && arr[j].second > arr[i].first) || (arr[i].second > arr[j].first && arr[j].second > arr[i].second);
}



void updateGraph(){

    for(int i = 0; i<arr.size(); i++)
        for(int j = 0; j<arr.size(); j++)
            if(connected(i, j)) G[i][j] = 1;

}



bool DFS(int st, int fn, bitset<101> &vis){

    if(vis.test(st)) return false;

    if(st == fn) return true;

    vis.set(st);

    for(int i = 0; i<arr.size(); i++) if(G[st][i] && DFS(i, fn, vis)) return true;

    return false;

}



int main() {

    ios::sync_with_stdio(0);
    cin>>n;
    while(n--){

        cin>>x>>a>>b;
        if(x == 1){
            arr.emplace_back(a, b);
            updateGraph();
        }else{
            vis.reset();
            cout<<((DFS(a-1, b-1, vis))? "YES\n":"NO\n");
        }

    }return 0;

}
