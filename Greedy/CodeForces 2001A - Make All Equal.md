```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[101], c[110];

int main(){
    
    scanf("%d", &t);
    while(t--){

        scanf("%d", &n); memset(c, 0, sizeof(c));
        for(int i = 0; i<n; ++i) scanf("%d", &arr[i]), c[arr[i]]++;
        int max = 0;
        for(int i = 0; i<=n; ++i) max = std::max(max, c[i]); 
        printf("%d\n", n-max);

    }return 0;

}
