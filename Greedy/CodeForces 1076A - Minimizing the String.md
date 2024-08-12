```cpp
#include <bits/stdc++.h>
using namespace std;

int n, idx;
string s, s1, s2;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for(int i = 0; i<n-1 && (s[i] <= s[i+1]);) idx = ++i;
    idx = min(idx, n-1); 
    for(int i = 0; i<n; ++i) if(i != idx) cout<<s[i]; cout<<'\n';
    return 0;

}
