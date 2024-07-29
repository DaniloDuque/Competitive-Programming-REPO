```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e5 + 20;
int n, M, arr[MAX], on[MAX], off[MAX], rslt;

signed main(){

    scanf("%lld %lld", &n, &M); 
    for(int i = 1; i<=n;) scanf("%lld", &arr[i++]); arr[n+1] = M;
    for(int i = 1; i<=n+1; ++i){
        on[i] = on[i-1] + (arr[i] - arr[i-1])*(i&1);
        off[i] = off[i-1] + (arr[i] - arr[i-1])*(!(i&1));
    }
    rslt = on[n+1];
    for(int i = 1; i<=n; ++i) rslt = max(rslt, on[i] - 1 + (off[n+1] - off[i]));
    printf("%lld\n", rslt);
    return 0;

}
