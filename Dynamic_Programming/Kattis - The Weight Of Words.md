```cpp
#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<vector<string>> dp;



string word(int curr, int w, string s = ""){

    if(w < 0 || curr > n) return "";
    
    if(curr == n && !w) return s;

    if(dp[curr][w] != "0") return dp[curr][w];
    
    dp[curr][w] = "";

    for(char i = 'a'; i<='z'; ++i){

        dp[curr][w] = word(curr + 1, w - i + 96, s + i);

        if(dp[curr][w].length()) return dp[curr][w];

    }return dp[curr][w];

}



int main() {

    ios::sync_with_stdio(0); cout.tie(NULL);
    cin>>n>>w;
    dp.assign(n+1, vector<string>(w+1, "0"));
    string rslt = word(0, w);
    cout<<((rslt.length())? rslt: "impossible")<<'\n';
    return 0;

}
