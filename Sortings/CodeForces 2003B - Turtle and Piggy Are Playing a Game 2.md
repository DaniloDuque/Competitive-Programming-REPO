```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[(int)1e5+20];

int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        for(int i = 0; i<n;) scanf("%d", &arr[i++]);
        sort(arr, arr+n);
        printf("%d\n", arr[n>>1]);

    }return 0;

}
