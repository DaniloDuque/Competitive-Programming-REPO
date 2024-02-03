```cpp
#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>a>>b>>c;
    cout<<std::max({a+(b*c), a*(b+c), a*b*c, (a+b)*c, (a*b)+c, a+b+c})<<'\n';
    return 0;

}
