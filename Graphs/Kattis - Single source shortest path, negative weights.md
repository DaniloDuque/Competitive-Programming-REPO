```cpp
#include <bits/stdc++.h>
using namespace std;


#define duo pair<int, int>
#define oo 20000000


vector<vector<duo>> G;
int n, m, q, st, v1, v2, w;
vector<int> dp;
bool blank = false;



void BellmanFord() {
    
    dp.assign(n+1, oo);
    dp[st] = 0;
    
    for (int i = 0; i<n-1; ++i)
        for (int u = 0; u<n; ++u)
            for (duo edge : G[u])
                if (dp[u] != oo && dp[edge.first] > dp[u] + edge.second)
                    dp[edge.first] = dp[u] + edge.second;

    for (int i = 0; i<n-1; ++i)
        for (int u = 0; u<n; ++u)
            for (duo edge : G[u])
                if (dp[u] != oo && dp[edge.first] > dp[u] + edge.second)
                    dp[edge.first] = -oo; 
    
}



int main(){

    ios::sync_with_stdio(0);
    while(cin>>n>>m>>q>>st && n){

        if(blank) cout<<'\n';
        G.assign(n, {});
        while(m--){

            cin>>v1>>v2>>w;
            G[v1].push_back({v2, w});

        }BellmanFord();
        while(q--){

            cin>>v1;
            (dp[v1] == -oo)? cout<<"-Infinity\n": (dp[v1] == oo)? cout<<"Impossible\n": cout<<dp[v1]<<'\n';

        }blank = true;

    }return 0;

}
