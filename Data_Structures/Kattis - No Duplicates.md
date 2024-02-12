```cpp
#include <bits/stdc++.h>
using namespace std;


unordered_map<string, int> dups;
string s;
bool flag = false;


int main(){

    ios::sync_with_stdio(0); cin.tie(NULL);
    while(cin>>s) dups[s]++;
    for(auto &p: dups) if(p.second > 1) flag = 1;
    cout<<((flag)? "no\n": "yes\n");
    return 0;

}
