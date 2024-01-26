```cpp
#include <bits/stdc++.h>
using namespace std;

string s;
int dp[50];


int LIS(){

    int rslt = 0;
    for(int i = s.size()-1; i>=0; i--){
        for(int j = i+1; j<s.size(); j++) if(s[j] > s[i]) dp[i] = max(dp[i], 1 + dp[j]);
        rslt = max(rslt, dp[i]);

    }return rslt;

}


int main(){

    ios::sync_with_stdio(0);
    cin>>s;
    cout<<25-LIS()<<'\n';
    return 0;

}
