```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, k;

int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n>>k;
        for(int i = 0; i<n; i++)
        for(char j = 'a'; j < k+'a'; j++) cout<<j;
        cout<<'\n';

    }return 0;

}
