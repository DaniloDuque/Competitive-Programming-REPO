```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 10000
int q, n, x;
vector<vector<int>> G;
bitset<200> vis;



int dfs(int st, int i, int days = 0){

    if(st == i && days) return days;
    if(vis.test(i)) return oo;
    vis.set(i);
    int rslt = oo;
    for(int &j: G[i]) rslt = min(rslt, dfs(st, j, days+1));
    return rslt;

} 



int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin>>q;
    while(q--){

        cin>>n; G.assign(n, {});
        for(int i = 0; i<n; i++){
            cin>>x;
            G[i].push_back(--x);
        }

        for(int i = 0; i<n; i++){
            vis.reset();
            cout<<dfs(i, i)<<' ';
        }cout<<'\n';

    }return 0;

}
