```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, n, m;
vector<vector<char>> mat;

void solve(){        
    cin>>n>>m;
    mat.assign(n, vector<char>(m, 0));
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j)
            cin>>mat[i][j];
    int max = 0, idx;
    for(int i = 0; i<n; ++i){
        int c = 0;
        for(char &k : mat[i]) c+=(k=='#');
        if(max < c) max=c, idx=i;
    }
    int j = 0;
    for(;mat[idx][j]!='#';++j);
    cout<<idx+1<<' '<<j+(max>>1)+(max&1)<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
