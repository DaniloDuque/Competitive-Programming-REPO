```cpp
#include <bits/stdc++.h>
using namespace  std;

#define int long
int t, n, k, arr[(int)2e5+10];

signed main(){

    scanf("%ld", &t);
    while(t--){
    
        scanf("%ld %ld", &n, &k);
        for(int i = 0; i<n; ++i) scanf("%ld", &arr[i]);
        sort(arr, arr+n, greater<int>());
        for(int i = 1; i<n && k; ++i, ++i){
            int x = min(k, arr[i-1]-arr[i]);
            arr[i] += x; k -= x;
        }int rslt = 0;
        for(int i = 0; i<n; ++i) rslt += (i&1)? -arr[i] : arr[i];
        printf("%ld\n", rslt);

    }return 0;

}
