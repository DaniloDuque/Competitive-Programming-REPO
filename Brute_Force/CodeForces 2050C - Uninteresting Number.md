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
int t=1, cnt[10];
string s;

bool solve(){        
    cin>>s; MSET(cnt, 0, 10);
    int sum = 0;
    for(char &c : s) sum += c-'0', cnt[c-'0']++;
    for(int i=0; i<=min(9, cnt[2]); ++i)
        for(int j=0; j<=min(9, cnt[3]); ++j)
            if((sum + i*2 + j*6)%9 == 0) return 1;
    return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
