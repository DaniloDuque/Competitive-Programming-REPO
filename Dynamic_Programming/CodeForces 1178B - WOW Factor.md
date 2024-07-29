```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e6+20;
string wow;
int WS[MAX], c;
bitset<MAX> os;

signed main(){
    cin>>wow;

    string n;
    for(int i = 0; i<wow.size(); ++i)
        if(wow[i] == 'o'){
            for(int j = 0; j<c-1; ++j) n.push_back('w');
            n.push_back('o');
            c = 0;
        }else c++;
    for(int i = 0; i<c-1; ++i) n.push_back('w');

    WS[0] = (n[0] == 'w'); 
    for(int i = 1; i<n.size(); ++i){
        WS[i] = WS[i-1] + (n[i] == 'w');
        if(n[i] == 'o') os.set(i);
    }
     
    int rslt = 0;
    for(int i = 0; i<wow.size(); ++i)
        if(os.test(i)) 
            rslt += WS[i] * (WS[n.size()-1] - WS[i]);

    cout<<rslt<<'\n';
    return 0;
}
