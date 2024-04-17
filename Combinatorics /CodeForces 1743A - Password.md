```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, x, fact[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};


int binomial_Coefficient(int n, int k){
    return fact[n]/(fact[k]*fact[n-k]);
}


int main(){

    scanf("%d", &t);
    while(t--){

        scanf("%d", &n);
        for(int i = 0; i<n; ++i) scanf("%d", &x);
        printf("%d\n", binomial_Coefficient(10-n, 2) * 6);

    }return 0;

}
