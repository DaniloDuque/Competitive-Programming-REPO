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
int t=1, n, k, arr[MAX];
string s;

void solve(){        
    cin>>n>>k>>s; MSET(arr, 0, n+1);
    ll cur=k;
    for(int i = 0; i<n && cur>0; i++){
        if((k&1) == s[i]-'0') arr[i]=1, cur--;
    }
    arr[n-1]+=cur;
    for(int i = 0; i<n; ++i)
        if((k-arr[i])&1) s[i]='1'-(s[i]-'0');
    cout<<s<<endl;
    for(int i = 0; i<n; ++i) cout<<arr[i]<<' '; cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}