```cpp
#include <bits/stdc++.h>
using namespace std;

long long n, m, a;

int main(){

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m>>a;
    cout<<((m+a-1)/a) * ((n+a-1)/a)<<'\n';
    return 0;

}
