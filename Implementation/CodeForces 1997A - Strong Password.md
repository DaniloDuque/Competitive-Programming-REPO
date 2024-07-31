```cpp
#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main(){
    
    cin>>t;
    while(t--){

        cin>>s;
        int ind = -1;
        for(int i = 1; s[i]; ++i) if(s[i] == s[i-1]) ind = i; 
        if(ind == -1) cout<<(char)((s[0]+1)%26 + 'a');
        for(int i = 0; s[i]; ++i) {
            if(i == ind) cout<<(char)((s[i]+1)%26 + 'a');
            cout<<s[i];
        }cout<<endl;

    }return 0;

}
