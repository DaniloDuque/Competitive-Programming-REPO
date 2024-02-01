```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;


int minDays(int n, int printers){

    if(n <= printers) return 1;

    if(dp[printers] != 20000) return dp[printers]; 

    return dp[printers] = 1 + min(minDays(n-printers, printers), minDays(n, printers<<1));

}


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    dp.assign(n, 20000);
    cout<<minDays(n, 1)<<'\n';
    return 0;

}
