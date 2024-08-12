```cpp
#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define int long

int t, n, dp[21][21];
string s;


int str2Int(int i, int j){
    int rslt = 0;
    for(; i <= j; ++i)
        rslt = rslt*10 + s[i] - '0';
    return rslt;
}

int BT(int i, int j){
   
    int c = str2Int(i, i);
    if(i == j) return c;
    if(i > j || i < 0 || j >= n) return -1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = min(c * BT(i+1, j), c + BT(i+1, j));

}


signed main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
    
        memset(dp, -1, sizeof(dp)); int min = INT_MAX;
        cin>>n>>s;
        for(int i = 0; i<n-1; ++i){
            int BT1 = BT(0, i-1), mid = str2Int(i, i+1), BT2 = BT(i+2, n-1); 
            if(BT1 != -1 && BT2 != -1) min = std::min({min, BT1*mid*BT2, BT1*mid+BT2, BT1+mid*BT2, BT1+mid+BT2});
            else if(BT1 != -1) min = std::min({min, BT1*mid, BT1+mid});
            else if(BT2 != -1) min = std::min({min, BT2*mid, BT2+mid});
            else min = std::min(min, mid);

        }cout<<min<<'\n';

    }return 0;


}
