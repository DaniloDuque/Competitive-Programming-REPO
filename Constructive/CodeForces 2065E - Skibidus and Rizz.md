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

string solve(){        
    cin>>n>>m>>k;
    if(max(n, m) < k || max(n, m)-k > min(n, m)) return "-1";
    string r = "";
    int mx = max(n, m), b=0;
    if(mx==n) n-=k;
    else m-=k, b=1;
    for(int i=0; i<k; ++i) r+=((b)? '1' : '0');
    int i=(r[0]=='1');
    while(n && m) {
        if(i) r+='0', n--;
        else r+='1', m--;
        i=!i;
    }while(n--) r+='0';
    while(m--) r+='1';
    return r;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
