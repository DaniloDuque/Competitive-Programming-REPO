```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 3e5+20;
int t=1, n, acc[2][MAX], d, rslt;
string s;

int dist(int i){return abs(i-1-(n-i+1));}

int solve(){        
    cin>>n>>s;
    for(int i=1; i<=n; ++i) acc[0][i]=(s[i-1]=='0')+acc[0][i-1]; 
    for(int i=1; i<=n; ++i) acc[1][i]=(s[i-1]=='1')+acc[1][i-1];
    d = MAX, rslt = -1;
    for(int i = 1; i<=n; ++i)
        if(dist(i)<d && acc[0][i-1]>=(i>>1) && (acc[1][n]-acc[1][i-1])>=(n-i+2)/2) 
            rslt=i-1, d=dist(i);
    return (rslt==-1)? n : rslt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
