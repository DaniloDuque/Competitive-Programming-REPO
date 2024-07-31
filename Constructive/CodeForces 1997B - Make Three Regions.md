```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
string s[2];

int main(){
    
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>s[0]>>s[1];
        int rslt = 0;
        for(int i = 1; i<n-1; ++i) 
            rslt += (s[0][i] == '.' && s[0][i-1] == '.' && s[0][i+1] == '.' && s[1][i] == '.' && s[1][i-1] == 'x' && s[1][i+1] == 'x');      
        for(int i = 1; i<n-1; ++i) 
            rslt += (s[1][i] == '.' && s[1][i-1] == '.' && s[1][i+1] == '.' && s[0][i] == '.' && s[0][i-1] == 'x' && s[0][i+1] == 'x');
        cout<<rslt<<'\n';

    }return 0;

}
