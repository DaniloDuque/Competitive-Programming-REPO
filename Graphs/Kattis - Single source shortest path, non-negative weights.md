```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, q, st, v1, v2, w;
vector<vector<pair<int, int>>> G;
vector<int> dp;
bitset<10000> msk;
bool blank = false;




struct compare{
    bool operator()(int i, int j){return dp[i] > dp[j];}
};



void dijkstra(){

    msk.reset(); int visits = dp[st] = 0;
    priority_queue<int, vector<int>, compare> pq;
    pq.push(st);

    while(!pq.empty()){

        int curr = pq.top(); pq.pop();

        for(auto neigh: G[curr])

            if(!msk.test(neigh.first) && dp[neigh.first] > dp[curr] + neigh.second){

                dp[neigh.first] = dp[curr] + neigh.second;
                pq.push(neigh.first);

            }

    }
    

}   




int main() {

    ios::sync_with_stdio(0);
    while(cin>>n>>m>>q>>st && n){

        if(blank) cout<<'\n';

        G.assign(n, {});
        dp.assign(n, 1<<29);
        while(m--){

            cin>>v1>>v2>>w;
            G[v1].push_back({v2, w});

        }dijkstra();
        while(q--){

            cin>>v1;
            (dp[v1] == 1<<29)? cout<<"Impossible\n": cout<<dp[v1]<<'\n';

        }blank = true;


    }return 0;

}
