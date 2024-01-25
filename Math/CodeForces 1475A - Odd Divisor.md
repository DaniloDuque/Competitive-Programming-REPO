```cpp
#include <bits/stdc++.h>
using namespace std;

int t;
long long n;

int main(){

    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){

        cin>>n;
        cout<<((n == (n&-n))? "NO\n": "YES\n");

    }return 0;

}
