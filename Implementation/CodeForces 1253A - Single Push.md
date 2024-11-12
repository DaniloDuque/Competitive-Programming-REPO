```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n, a[MAX], b[MAX];
vec<int> cur;

bool solve(){        
    cin>>n; cur.clear();
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    for(int i=0;i<n; ++i) cur.push_back(b[i]-a[i]);
    cur.erase(unique(ALL(cur)), cur.end());
    if(cur.back()==0) cur.pop_back();
    if(cur.size() && cur[0]==0) cur.erase(cur.begin());
    return cur.empty() || (cur.size()==1 && cur[0]>0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<((solve())? "YES" : "NO")<<endl;
    }return 0;
}
