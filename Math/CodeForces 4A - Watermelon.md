```cpp
#include <iostream>
using namespace std;

int n;

int main(){

    cin>>n;
    cout<<((n&1 || n == 2)? "NO\n": "YES\n");
    return 0;

}
