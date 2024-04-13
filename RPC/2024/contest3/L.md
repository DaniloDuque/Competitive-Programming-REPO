```cpp
#include <bits/stdc++.h>
using namespace std;

int r, c, k, v = 1;
string a, b;


bool exists(string &s, char c){
    return s.find(c) != std::string::npos;
}


int main(){

    cin>>r>>c>>k;
    while(r--){

        cin>>a>>b;
        v &= !(exists(a, '-') && exists(b, '*'));

    }cout<<((v)? "Y" : "N")<<'\n';
    return 0;

}
