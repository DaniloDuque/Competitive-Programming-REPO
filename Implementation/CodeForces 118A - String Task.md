```cpp
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

string s;
set<char> vowels = {'y', 'a', 'e', 'i', 'o', 'u'};

int main(){

    cin>>s;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    string k;
    for(char &c : s) if(!vowels.count(c)) k.push_back(c);
    for(char &c : k) cout<<'.'<<c; cout<<'\n';
    return 0;

}
