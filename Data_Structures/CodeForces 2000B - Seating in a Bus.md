```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[(int)2e5 + 20];

bool possible(){
    
    bitset<(int)2e5 + 20> seat;
    seat.set(arr[0]);
    for(int i = 1; i<n; ++i){
        int l = arr[i]-1, r = arr[i]+1;
        if(!seat.test(l) && !seat.test(r)) return 0;
        seat.set(arr[i]);
    }return 1;

}

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d", &n);
        for(int i = 0; i<n;) scanf("%d", &arr[i++]);
        puts(possible()? "YES" : "NO");

    }return 0;

}
