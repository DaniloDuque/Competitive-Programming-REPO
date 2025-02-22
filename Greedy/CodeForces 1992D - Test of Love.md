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
int t=1, n, m, k;
string s;

bool solve(){        
    cin>>n>>m>>k>>s;
    s = "L"+s+"L";
    int swim=0, i=0;
    while(i<=n) {
        if(s[i]=='C') return 0;
        if(s[i]=='W') {i++; swim++; continue;}
        if(i+m > n) {i=n+1; break;}
        bool jump=0;
        for(int j=i+m; j>i; --j) 
            if(s[j]=='L') {
                jump=1;
                i=j;
                break;
            }
        if(jump) continue;
        for(int j=i+m; j>i; --j) 
            if(s[j]=='W'){
                i=j;
                jump=1;
                break;
            }
        if(!jump) return 0;
    }return i>n && swim<=k;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
