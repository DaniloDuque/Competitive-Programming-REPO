```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, c[27];
string s;

int main(){

    cin>>t;
    while(t--){
        cin>>n>>s; memset(c, 0, sizeof(c));
        string r(n, '0');
        for(char &k:s) c[k-'a']++;
        for(int i = 0; i<27; ++i)
            for(int j = 0; j<n && c[i]; j+=2){ 
                if(r[j] != '0') while(r[j] != '0') ++j; 
                r[j] = i+'a', c[i]--; 
            }

        for(int i = 0, j = 0; j<n, i<27; ++j){
            if(!c[i]) while(!c[i] && i<27) ++i;
            if(r[j] == '0') r[j] = i+'a', c[i]--;
        }
        cout<<r<<'\n';

    }return 0;

}
