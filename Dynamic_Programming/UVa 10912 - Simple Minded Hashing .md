```cpp
#include <bits/stdc++.h>
using namespace std;


int l, s, Case = 0, dp[27][352][27];


int numStrings(int len, int sum, int last){

    if(len < 0) return 0;
    if(!(len|sum)) return 1;

    int &mem = dp[len][sum][last];
    if(mem != -1) return mem;
    mem = 0;

    for(int i = last+1; i<=(min(26, sum)); ++i) mem += numStrings(len-1, sum-i, i);
    return mem;

}



int main(){

    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d", &l, &s) && l){

        printf("Case %d: %d\n", ++Case, (l > 26 || s > 351)? 0: numStrings(l, s, 0));

    }return 0;
   

}
