```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[41];

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d", &n);
        for(int i = 0; i<n;) scanf("%d", &arr[i++]);
        if(n == 2 && arr[1] - arr[0] > 1) puts("YES");
        else puts("NO");

    }return 0;

}
