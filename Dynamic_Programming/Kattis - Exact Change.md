```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAX 20000
int t, p, n, coins[101], dp[MAX];


int main() {

    ios::sync_with_stdio(0);    
    cin>>t;
    while(t--){

        cin>>p>>n;
        fill(dp, dp+MAX, MAX);
        for(int i = 0; i<n; i++) cin>>coins[i];

        dp[0] = 0;
        for(int i = 0; i<n; i++)
            for(int j = MAX-1; j>=coins[i]; --j)
                dp[j] = min(dp[j], dp[j-coins[i]] + 1);

        int i = p;
        while(dp[i++] == MAX);
        cout<<i-1<<" "<<dp[i-1]<<'\n';


    }return 0;

}
