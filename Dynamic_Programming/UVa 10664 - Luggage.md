```cpp
#include <bits/stdc++.h>
using namespace std;

int m, n;

vector<int> nums;
unordered_map<int, bool> dp;



bool equalWeight(int i = 0, int sum1 = 0, int sum2 = 0){

    if(i == nums.size()) return sum1 == sum2;

    if(dp[i]) return dp[i];

    return dp[i] = max(equalWeight(i+1, sum1 + nums[i], sum2), equalWeight(i+1, sum1, sum2 + nums[i]));

}



int main(){

    ios::sync_with_stdio(false);
    cin>>m;
    while(m--){

        nums.clear(); dp.clear();
        while(cin>>n){

            nums.push_back(n);
            if(cin.peek() == '\n') break;

        }cout<<((equalWeight())? "YES": "NO")<<'\n';


    }return 0;

}
