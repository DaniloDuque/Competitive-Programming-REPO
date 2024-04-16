```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long
int t, n; 

signed main(){

    scanf("%ld", &t);
    while(t--){

        scanf("%ld", &n);
        printf((!(n%4))? "YES\n" : "NO\n");

    }return 0;

}
