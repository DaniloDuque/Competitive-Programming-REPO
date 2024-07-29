```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, arr[(int)2e5 + 20], M;
set<int> U;
vector<int> rslt;

signed main(){

    scanf("%lld", &n);
    for(int i = 0; i<n;){
        scanf("%lld", &arr[i]);
        U.insert(arr[i++]);
    }

    sort(arr, arr+n);
    for(int i = 0; i<n && M < 3; ++i)
        for(int j = 0; j<31LL; ++j)
            if(U.count(arr[i] + (1LL<<j))){
                if(M < 2){
                    M = 2;
                    rslt = {arr[i], arr[i] + (1LL<<j)};
                }
                if(M < 3 && U.count(arr[i] + (1LL<<(j+1)))){
                    M = 3;
                    rslt = {arr[i], arr[i] + (1LL<<j), arr[i] + (1LL<<(j+1))};
                }
            }

    if(!M){ M = 1LL; rslt = {arr[0]};}
    printf("%lld\n", M);
    for(int i : rslt) printf("%lld ", i); puts("");
    return 0;
}
