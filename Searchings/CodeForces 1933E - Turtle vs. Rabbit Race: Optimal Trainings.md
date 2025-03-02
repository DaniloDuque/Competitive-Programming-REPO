```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long
const int MAX = 1e5+20;
int t, n, arr[MAX], q, l, u;

int closest(int l, int u){
    int v = u+(l? arr[l-1]:0), idx = lower_bound(arr, arr+n, v)-arr;
    if(idx <= l) return l+1;
    if(idx == n) return n;
    return idx+(v-arr[idx-1] >= arr[idx]-v);
}

signed main(){

    scanf("%ld", &t);
    while(t--){

        scanf("%ld", &n);
        for(int i = 0; i<n;) scanf("%ld", &arr[i++]);
        partial_sum(arr, arr+n, arr); scanf("%ld", &q);
        while(q--){
    
            scanf("%ld %ld", &l, &u);
            printf("%ld ", closest(--l, u));

        }puts("");

    }return 0;

}
