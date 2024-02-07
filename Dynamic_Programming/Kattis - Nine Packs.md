```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 100001
int h, b, hotdogs[101], buns[101], dpHot[101][oo], dpBun[101][oo], rslt = oo;


//returns minimum number of packs, needed to complete 'i' hotdogs
int minPacks(int i, int sum, int dp[][oo], int arr[]){

    if(i == -1 || sum <= 0) return (sum)? oo: 0;

    if(dp[i][sum] != -1) return dp[i][sum];

    return dp[i][sum] = min(1 + minPacks(i-1, sum - arr[i], dp, arr), minPacks(i-1, sum, dp, arr));

}


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>h;
    for(int i = 0; i<h; i++) cin>>hotdogs[i];
    cin>>b;    
    for(int i = 0; i<b; i++) cin>>buns[i];
    memset(dpHot, -1, sizeof(dpHot));
    memset(dpBun, -1, sizeof(dpBun));

    for(int i = 1; i<oo; i++)  rslt = min(rslt, minPacks(h-1, i, dpHot, hotdogs) + minPacks(b-1, i, dpBun, buns));

    (rslt >= oo)? cout<<"impossible\n": cout<<rslt<<'\n';
    return 0;

}
