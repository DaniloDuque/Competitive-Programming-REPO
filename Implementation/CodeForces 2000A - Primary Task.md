```cpp
#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool important(){
    if(s.size() <= 2 || s[0] != '1' || s[1] != '0') return 0;
    if(s.size() == 3) return s[2] >= '2';
    return s[2] != '0';
}

int main(){

    cin>>t;
    while(t--){
        cin>>s; 
        cout<<(important()? "YES":"NO")<<'\n';
    }return 0;

}
