```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long long
int t, n, arr[502], pst;


signed main(){

    scanf("%lld", &t);
    while(t--){

        scanf("%lld", &n);
        for(int i = 0; i<n-1; ++i) scanf("%lld", &arr[i]);
        pst = 1000;
        for(int i = 0; i<n; ++i){
            printf("%lld ", pst);
            pst += arr[i];
        }
        puts("");

    }return 0;

}
