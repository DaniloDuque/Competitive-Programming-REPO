```cpp
#include <bits/stdc++.h>
using namespace std;


int t;
string l;


int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){

        cin>>l;
        cout<<(l[0]-'a')*25 + (l[1]-'a' + (l[0] > l[1]))<<'\n';

    }return 0;

}
