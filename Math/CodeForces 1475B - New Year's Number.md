```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n;
        cout<<((n%2020 <= n/2020)? "YES\n": "NO\n");

    }return 0;

}
