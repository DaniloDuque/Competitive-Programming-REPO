```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
string mat[3];

bool wins(char x){
    for(int i=0; i<3; ++i) if(mat[i][0]==x && mat[i][1]==x && mat[i][2]==x) return 1;
    for(int i=0; i<3; ++i) if(mat[0][i]==x && mat[1][i]==x && mat[2][i]==x) return 1;
    return mat[0][0]==x && mat[1][1]==x && mat[2][2]==x || mat[2][0]==x && mat[1][1]==x && mat[0][2]==x;
}

string solve(){        
    for(int i=0; i<3; ++i) cin>>mat[i];
    if(wins('X')) return "X";
    if(wins('+')) return "+";
    if(wins('O')) return "O";
    return "DRAW";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
