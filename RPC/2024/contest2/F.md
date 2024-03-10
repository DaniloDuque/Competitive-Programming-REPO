```cpp
#include <bits/stdc++.h>
using namespace std;


long n, c, arr[100001];


int main(){

    scanf("%ld %ld", &n, &c);
    for(int i = 0; i<n; ++i) scanf("%ld", &arr[i]);
    for(int i = 1; i<n; ++i) arr[i] += max(0L, arr[i-1] - c);
    
    long index = -1, min = INT_MAX;
    for(int i = 0; i<n; ++i)
        if((i + (arr[i]/c)) < n && (arr[i]/c + 1) < min){
            index = i;
            min = arr[i]/c + 1;
        } 

    (index == -1)? printf("impossible\n"): printf("%ld\n", index);
    return 0;

}
