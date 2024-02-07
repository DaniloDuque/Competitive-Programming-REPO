```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n;
string s;


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n>>s;
        int i = 0, j = n-1;
        for(;s[i] != 'B'; i++);
        for(;s[j] != 'B'; j--);
        cout<<j-i+1<<'\n';

    }return 0;

}
