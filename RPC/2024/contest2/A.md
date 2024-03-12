```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long
int n, m, k, arr[100001];


signed main(){

    scanf("%ld %ld %ld", &n, &m, &k);
    for(int i = 0; i<n; ++i) scanf("%ld", &arr[i]);
    sort(arr, arr+n, greater<int>());
    long double tot = 0, sum = 0;
    for(int i = 0; i<n; ++i) tot += arr[i];
    for(int i = 0; i<m+k; ++i) sum += arr[i];
    printf("%.9Lf\n", min(sum, tot)/tot*100.0);
    return 0;

}
