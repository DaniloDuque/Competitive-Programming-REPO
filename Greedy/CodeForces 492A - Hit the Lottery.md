```cpp
#include <bits/stdc++.h>
using namespace std;

int n, c=0;
int bills[] = {1, 5, 10, 20, 100};

int main(){

    cin>>n;
    for(int i = 4; i>=0; i--){

        c += n/bills[i];
        n %= bills[i];

    }cout<<c<<'\n';
    return 0;

}
