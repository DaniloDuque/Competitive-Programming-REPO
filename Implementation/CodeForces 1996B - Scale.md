```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, k;
string grid[1001];

int main(){
    
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin>>t;
    while(t--){
    
        cin>>n>>k;
        for(int i = 0; i<n; ++i) cin>>grid[i];
        for(int i = 0; i<n; i += k){
            for(int j = 0; j<n; j += k)
                cout<<grid[i][j];
            cout<<'\n';
        }
    

    }return 0;

}
