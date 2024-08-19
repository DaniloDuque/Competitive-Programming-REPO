```cpp
#include <bits/stdc++.h>
using namespace std;

int t, c[3], k[5]; 

bool sol(){
    if(c[0] < 0 || c[1] < 0 || c[2] < 0) return 0;
    int a = c[0]-min(c[0], k[3]); k[3] = max(0, k[3]-c[0]), c[0] = a;
    a = c[1]-min(k[4], c[1]); k[4] = max(0, k[4]-c[1]), c[1] = a;
    return k[3]+k[4] <= c[2];
}

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d %d %d %d %d %d %d %d", &c[0], &c[1], &c[2], &k[0], &k[1], &k[2], &k[3], &k[4]);
        c[0]-=k[0], k[0] = 0;
        c[1]-=k[1], k[1] = 0;
        c[2]-=k[2], k[2] = 0;
        puts(sol()? "YES" : "NO");


    }return 0;

}
