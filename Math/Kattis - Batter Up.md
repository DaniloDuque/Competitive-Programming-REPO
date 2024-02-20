```cpp
#include <bits/stdc++.h>
using namespace std;


int n, x, k = 0;
long double sum = 0;


int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(n--){
        cin>>x;
        if(x >= 0){
            sum += x;
            k++;
        }
    }cout<<setprecision(10)<<sum/k<<'\n';
    return 0;

}
