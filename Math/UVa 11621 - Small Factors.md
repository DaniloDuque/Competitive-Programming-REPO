```cpp
#include <bits/stdc++.h>
using namespace std;



#define ll unsigned long long

ll n;



ll Next(ll n){

    ll min = ULLONG_MAX;
    for(int i = 0; (1<<i) < (n<<1); i++){

        ll curr = 1<<i;
        while(curr < n) curr *= 3;
        min = std::min(min, curr);

    }return min;

}


int main(){

    ios::sync_with_stdio(false);
    while(cin>>n && n) cout<<Next(n)<<'\n';
    return 0;

}
