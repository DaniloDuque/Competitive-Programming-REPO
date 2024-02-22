```cpp
#include <bits/stdc++.h>
using namespace std;


int n, zero = 0, one = 0;
char x;


int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(n--){
        cin>>x;
        (x == '1')? one++: zero++;

    }cout<<abs(zero-one)<<'\n';
    return 0;

}
