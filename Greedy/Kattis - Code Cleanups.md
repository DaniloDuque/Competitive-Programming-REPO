```cpp
#include <bits/stdc++.h>
using namespace std;


int n, c, cleaned, days[370];


int main(){

    scanf("%d", &n);
    for(int i = 0; i<n; ++i) scanf("%d", &days[i]); 
    for(int i = 1; i<n; ++i){

        int dirtiness = 0;
        for(int j = cleaned; j<i; ++j) dirtiness += days[i] - days[j];
        if(dirtiness >= 20){
            cleaned = i;
            c++;
        }

    }printf("%d\n", c + (cleaned != n));
    return 0;

}
