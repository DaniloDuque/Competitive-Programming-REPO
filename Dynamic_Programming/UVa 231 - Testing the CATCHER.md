```cpp
#include <bits/stdc++.h>
using namespace std;


int n, test = 0;
bool blank = false;
vector<int> heights, dp;



int LIS(){

    int LS = 1;
    dp.assign(heights.size(), 1);
    for(int i = dp.size()-1; i>=0; i--){

        int max = 0;
        for(int j = i+1; j<dp.size(); j++) if(heights[j] < heights[i]) max = std::max(max, dp[j]);
        dp[i] += max;
        LS = std::max(dp[i], LS);

    }return LS;


}



int main(){

    ios::sync_with_stdio(false);
    while(cin>>n && n != -1){

        heights.clear(); heights.push_back(n);
        while(cin>>n && n != -1) heights.push_back(n);

        if(test) cout<<'\n';
        cout<<"Test #"<<++test<<":\n";
        cout<<"  maximum possible interceptions: "<<LIS()<<'\n';

    }return 0;

}
