```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, arr[1000];
long double sum, avg;



int main(){

    scanf("%d", &t);
    while(t--){

        sum = 0;
        scanf("%d", &n);
        for(int i = 0; i<n; ++i){
            scanf("%d", &arr[i]);
            sum += arr[i];

        }avg = sum/n; sum = 0;
        for(int i = 0; i<n; ++i) sum += (arr[i] > avg);
        printf("%.3Lf%%\n", sum/n * 100.0);


    }return 0;

}
