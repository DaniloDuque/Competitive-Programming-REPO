```cpp
#include <bits/stdc++.h>
using namespace std;

int n, coins[100];


int main(){

    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>coins[i];

    sort(coins, coins+n, greater<int>());

    int sum1 = 0, sum2 = 0, i = 0;
    for(int i = 0; i<n; i++) sum2 += coins[i];

    while(sum1 <= sum2){

        sum1 += coins[i];
        sum2 -= coins[i++];

    }cout<<i<<'\n';
    return 0;

}
