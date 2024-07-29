```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, arr[3];

int sum(){
    return arr[0]+arr[1]+arr[2];
}
signed main(){
    
    scanf("%lld", &t);
    while(t--){

        scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr+3);
        puts((sum()%9 == 0 && sum()/9 <= arr[0])? "YES" : "NO");

    }return 0;

}
