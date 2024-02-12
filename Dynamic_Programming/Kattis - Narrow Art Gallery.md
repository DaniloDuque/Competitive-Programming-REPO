```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 100000
#define dp(x) (dp[i][j][(x)])
int n, k, arr[201][2], dp[201][201][3];



int minRoom(int i, int j, char l){
    
    if(i == n) return (!j)? 0: oo;

    if(dp(l) != -1) return dp(l);

    dp(l) = minRoom(i+1, j, 2);

    if(l) dp(l) = min(dp(l), arr[i][1] + minRoom(i+1, j-1, 1));

    if(l != 1) dp(l) = min(dp(l), arr[i][0] + minRoom(i+1, j-1, 0));

    return dp(l);

}


int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n>>k && n){

        for(int i = 0; i<n; i++) cin>>arr[i][0]>>arr[i][1];
        int sum = 0;        
        for(int i = 0; i<n; i++) sum += arr[i][0] + arr[i][1];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<=k; j++)
                dp(0) = dp(1) = dp(2) = -1;

        cout<<sum - minRoom(0, k, 2)<<'\n';

    }return 0;

}
