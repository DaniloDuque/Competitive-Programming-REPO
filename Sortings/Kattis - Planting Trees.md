```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long
int n, arr[100001];


signed main(){

    scanf("%ld", &n);
    for(int i = 0; i<n; ++i) scanf("%ld", &arr[i]);
    sort(arr, arr+n, greater<int>());
    int max = -1;
    for(int i = 0; i<n; ++i) max = std::max(max-1, arr[i]);
    printf("%ld\n", n + max + 1);
    return 0;

}
