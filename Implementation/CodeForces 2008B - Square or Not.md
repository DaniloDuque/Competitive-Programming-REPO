```cpp
  #include <bits/stdc++.h>
#include <cmath>
using namespace std;

int t, n;
string s;
char mat[1000][1000];

bool sqr(){
    int sq = sqrt(n);
    if(n != sq*sq) return 0;
    for(int i = 0; s[i]; ++i) mat[i/sq][i%sq]=s[i];
    for(int i = 0; i<sq; ++i) if(mat[0][i]!='1' || mat[sq-1][i]!='1') return 0;
    for(int i = 0; i<sq; ++i) if(mat[i][0]!='1' || mat[i][sq-1]!='1') return 0;
    for(int i = 1; i<sq-1; ++i)
        for(int j = 1; j<sq-1; ++j)
            if(mat[i][i]!='0') return 0;
    return 1;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>s;
        cout<<(sqr()? "YES" : "NO")<<'\n';
    }return 0;

}
