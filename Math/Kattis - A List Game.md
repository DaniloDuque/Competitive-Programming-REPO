```cpp
#include <bits/stdc++.h>
using namespace std;


int n, p = 2, c;

bool isPrime(){

    int i = 3;
    if(!(n&1)) return 0;
    while(i*i <= n){

        if(!(n%i)) return 0;
        i += 2;

    }return 1;

}


int main(){

    cin>>n; 
    if(isPrime()) puts("1");
    else{
        for(;n!=1; ++p)
            for(;!(n%p); n /= p) ++c;
        cout<<c<<'\n';

    }return 0;

}
