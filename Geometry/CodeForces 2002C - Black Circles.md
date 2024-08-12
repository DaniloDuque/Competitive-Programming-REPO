```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, n, circles[2][(int)2e5 + 20], xs, ys, xe, ye;

int sqr(int x){return x*x;}

int distsqr(int a, int b){return sqr(a - xe) + sqr(b - ye);}

signed main(){
    
    scanf("%lld", &t);
    while(t--){
    
        scanf("%lld", &n);
        for(int i = 0; i<n; ++i) scanf("%lld %lld", &circles[0][i], &circles[1][i]);
        scanf("%lld %lld %lld %lld", &xs, &ys, &xe, &ye);
        int minD = distsqr(circles[0][0], circles[1][0]);
        for(int i = 1; i<n; ++i) minD = min(minD, distsqr(circles[0][i], circles[1][i]));
        puts((distsqr(xs, ys) < minD)? "YES" : "NO");

    }return 0;

}
