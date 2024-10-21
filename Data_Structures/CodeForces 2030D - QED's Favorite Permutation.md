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
int t=1, n, q, arr[MAX], x, inv[MAX], diff[MAX];
string s;
set<int> prob;

void solve(){        
    cin>>n>>q;
    for(int i = 0; i<n; ++i) cin>>arr[i], --arr[i];
    for(int i = 0; i<n; ++i) inv[arr[i]]=i;
    MSET(diff, 0, n);
    for(int i = 0; i<n; ++i){
        diff[min(i, inv[i])]++;
        diff[max(i, inv[i])]--;
    }partial_sum(diff, diff+n, diff);
    cin>>s; prob.clear();
    for(int i = 0; i<n-1; ++i) if(s[i]=='L' && s[i+1]=='R' && diff[i]) prob.insert(i);
    while(q--){
        cin>>x; --x;
        s[x] = (s[x]=='L')? 'R' : 'L';
        if(s[x-1]=='L' && s[x]=='R' && diff[x-1]) prob.insert(x-1);
        else prob.erase(x-1);
        if(s[x]=='L' && s[x+1]=='R' && diff[x]) prob.insert(x);
        else prob.erase(x);
        cout<<((prob.size())? "NO" : "YES")<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
