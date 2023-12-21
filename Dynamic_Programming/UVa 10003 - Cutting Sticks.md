```cpp
#include <bits/stdc++.h>
using namespace std;

int l, n, c;


vector<int> cuts;
vector<vector<int>> memo;






int minCost(int i, int j){

    int low = upper_bound(cuts.begin(), cuts.end(), i) - cuts.begin();     //binary search possible cuts in range(i, j)
    int high = lower_bound(cuts.begin(), cuts.end(), j) - cuts.begin();

    if(low >= high) return 0; // Base case: no possible cuts

    if(memo[i][j] != INT_MAX) return memo[i][j];

    for(int k = low; k<high; k++) memo[i][j] = min(memo[i][j], minCost(i, cuts[k]) + minCost(cuts[k], j));

    return memo[i][j] += (j-i);


}






int main(){

    ios::sync_with_stdio(0);
    cin>>l;
    while(l){

        cin>>n; cuts.assign(n, 0); memo.assign(l+1, vector<int>(l+1, INT_MAX));
        for(int i = 0; i<n; i++) cin>>cuts[i];
        cout<<"The minimum cutting is "<<minCost(0, l)<<".\n";
        cin>>l;


    }return 0;

}
