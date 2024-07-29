```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long
int n;
vector<int> s;


int product(vector<int> &k){
    int p = 1;
    for(int i = 0; i<s.size(); i++)
        p *= (k[i] > 0)? k[i] : 1;
    return p;
}

signed main(){

    cin>>n;
    while(n){
        s.push_back(n%10);
        n /= 10;
    }

    reverse(s.begin(), s.end());
    int rslt = product(s);
    for(int i = 0; i<s.size(); ++i){
        vector<int> help = s;
        help[i] = s[i] - 1;
        for(int j = i+1; j<s.size(); ++j) help[j] = 9;
        rslt = max(rslt, product(help));
    }

    cout<<rslt<<'\n';
    return 0;
}
