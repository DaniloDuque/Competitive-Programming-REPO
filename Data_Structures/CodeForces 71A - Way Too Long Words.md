```cpp
#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main(){

    cin>>t;
    while(t--){

        cin>>s;
        (s.length() > 10)? cout<<s[0]<<s.length()-2<<s.back()<<'\n': cout<<s + '\n';

    }return 0;

}
