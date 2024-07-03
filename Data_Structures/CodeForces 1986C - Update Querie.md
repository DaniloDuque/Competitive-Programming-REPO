```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m, x;
set<int> ind;
string s, c;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        
        ind.clear();
        cin>>n>>m>>s;
        for(int i = 0; i<m; ++i){
            cin>>x;
            ind.insert(--x);
        }cin>>c;
        sort(c.begin(), c.end());
        
        int i = 0;
        for(int idx : ind) s[idx] = c[i++];
        cout<<s<<'\n';

    }return 0;

}
