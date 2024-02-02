```cpp
#include <bits/stdc++.h>
using namespace std;


string s;  

char hello[5] = {'h', 'e', 'l', 'l', 'o'};


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>s;
    int curr = 0;
    for(int i = 0; i<s.length() && curr < 5; ++i) if(s[i] == hello[curr]) curr++;

    cout<<((curr == 5)? "YES\n": "NO\n");
    return 0;

}
