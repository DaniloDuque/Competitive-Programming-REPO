```cpp
#include <bits/stdc++.h>
using namespace std;


#define MAX 200002
#define int long long
int t, n, k, b, s, arr[MAX], pnts[MAX];
bitset<MAX> vis;


int travel(int i, int k){
    if(!k) return 0;
    if(arr[i] > n || vis.test(i)) return pnts[i]*k;
    vis.set(i);
    return max(pnts[i] * k, travel(arr[i], k-1) + pnts[i]);
}


signed main(){

    scanf("%lld", &t);
    while(t--){

        scanf("%lld %lld %lld %lld", &n, &k, &b, &s);
        for(int i = 1; i<=n; ++i) scanf("%lld", &arr[i]);
        for(int i = 1; i<=n; ++i) scanf("%lld", &pnts[i]);
        vis.reset();
        int sasha = travel(s, k);
        vis.reset();
        int bodya = travel(b, k);
        printf((sasha > bodya)? "Sasha\n" : (bodya > sasha)? "Bodya\n" : "Draw\n");

    }return 0;

}
