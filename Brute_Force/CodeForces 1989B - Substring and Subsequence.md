```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
string s, w;

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(n--){

        cin>>s>>w;
        int ans = 1000;
        for(int i = 0; i<w.size(); ++i){
            int p = i;
            for(int j = 0; j<s.size(); ++j) p += (p < w.size() && s[j] == w[p]);
            ans = min(ans, (int)w.size() + (int)s.size() - p + i);
        }
        cout<<ans<<'\n';

    }return 0;

}
