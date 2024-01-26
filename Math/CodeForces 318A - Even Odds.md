```cpp
#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main(){

    ios::sync_with_stdio(0);
    cin>>n>>k;
    cout<<((k > (n&1) + (n>>1))? 2*(k - (n>>1) - (n&1)): 2*k - 1)<<'\n';
    return 0;

}
