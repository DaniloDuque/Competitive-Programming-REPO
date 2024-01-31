```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 2000006
int n, coins[100];
vector<int> dp, greed;



void DP(){

    for(int i = 1; i<oo; i++)
        for(int j = 0; j<n && coins[j] <= i; j++)
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);

}

void Greedy(){

    int k = 0;
    for(int i = 1; i<oo; i++){
        while(k < n-1 && coins[k+1] <= i) k++;
        greed[i] = greed[i - coins[k]] + 1;
    }

}

bool isCanonical(){

    DP(); Greedy();
    for(int i = 1; i<oo; i++) if(dp[i] != greed[i]) return false;
    return true;

}


int main() {

    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>coins[i];

    dp.assign(oo, oo); greed.assign(oo, oo);
    dp[0] = greed[0] = 0;

    cout<<((isCanonical())? "canonical\n": "non-canonical\n");
    return 0;

}
