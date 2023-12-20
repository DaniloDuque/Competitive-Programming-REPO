```cpp
#include <bits/stdc++.h>
using namespace std;

int n, q, x, y, newNum; 
vector<int> nums;
vector<vector<int>> dp;





void accumulatedLists(){

    dp.assign(10, vector<int>(n+1, 0));
    for(int i = 1; i<=n; i++){

        dp[nums[i-1]][i] = 1;
        for(int j = 0; j<10; j++) dp[j][i] += dp[j][i-1]; //this accumulates the number of "nums[i]" inside ith row

    }
   
}


int query(int i, int j){

    int diff = 0;
    for(int k = 0; k<10; k++) diff += (dp[k][j] > dp[k][i-1]); //only sum 1 if there was a new number inside the range [i, j]
    return diff;

}




int main(){

    ios::sync_with_stdio(0);
    while(cin>>n){

        nums.assign(n, 0);
        for(int i = 0; i<n; i++) cin>>nums[i];
        cin>>q;
        accumulatedLists();
        while(q--){

            cin>>x>>y;
            cout<<query(x, y)<<'\n';

        }

    }return 0;

}
