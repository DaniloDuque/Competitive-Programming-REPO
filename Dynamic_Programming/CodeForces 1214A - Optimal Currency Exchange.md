```cpp
#include <bits/stdc++.h>
using namespace std;

int n, d, e, D, E, dp[(int)1e8 + 20];

int din(int i){
    if(!i) return 0;
    int &cc = dp[i];
    if(cc != -1) return cc;
    cc = i;
    if(!(i%E) || !(i%D)) return cc = 0;
    if(i >= E) cc = min(cc, din(i - E));
    if(i >= D) cc = min(cc, din(i - D));
    return cc;
}

signed main(){
    scanf("%d %d %d", &n, &d, &e);
    memset(dp, -1, sizeof(dp));
    D = d; E= 5*e;
    printf("%d\n", din(n));
    return 0;
}
