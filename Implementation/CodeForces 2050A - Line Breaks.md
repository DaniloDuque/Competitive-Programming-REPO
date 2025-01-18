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
const int MAX = 51, MOD = 1e9+7;
int t=1, n, m;
string arr[MAX];

int solve(){        
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    int i = 0, cnt = 0;
    while(i<n && cnt+arr[i].size() <= m) cnt += arr[i++].size();
    return i;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
