```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, k, x;
vector<bitset<1001>> notes;
vector<int> tune;
vector<vector<int>> dp;


int minChanges(int i, int piano){

    if(i == m) return 0;

    if(dp[i][piano] != INT_MAX) return dp[i][piano];

    if(notes[piano].test(tune[i])) return dp[i][piano] = minChanges(i+1, piano);

    for(int nxt = 0; nxt<n; nxt++) if(notes[nxt].test(tune[i])) dp[i][piano] = min(dp[i][piano], 1 + minChanges(i+1, nxt));

    return dp[i][piano];

}


int main() {

    ios::sync_with_stdio(0);
    cin>>n>>m;
    notes.assign(n, bitset<1001>(0));
    tune.assign(m, 0);
    dp.assign(m, vector<int>(n, INT_MAX));

    for(int i = 0; i<n; i++){
        cin>>k;
        for(int j = 0; j<k; j++){
            cin>>x;
            notes[i].set(x);
        }

    }for(int i = 0; i<m; i++) cin>>tune[i];
    
    int rslt = INT_MAX;
    for(int i = 0; i<n; i++) rslt = min(rslt, minChanges(0, i));
    cout<<rslt<<'\n';
    return 0;

}
