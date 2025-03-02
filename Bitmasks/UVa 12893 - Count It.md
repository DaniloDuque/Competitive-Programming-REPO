```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long unsigned


int n;
ll x;


int func(ll x){

    if(!x) return 0;
    return x%2 + func(x>>1);

}

int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){

        cin>>x;
        cout<<func(x)<<'\n';

    }return 0;

}
