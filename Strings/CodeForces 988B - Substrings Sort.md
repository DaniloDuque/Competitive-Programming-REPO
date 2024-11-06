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
const int MAX = 101, MOD = 1e9+7;
int t=1, n;
string arr[MAX];

bool isSubstr(string &a, string &b){
    return b.find(a) != string::npos;
}

bool cmp(string &a, string &b){
    return a.size() < b.size();
}

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(arr, arr+n, cmp);
    for(int i = 1; i<n; ++i) if(!isSubstr(arr[i-1], arr[i])){cout<<"NO\n"; return;}
    cout<<"YES\n";
    for(int i = 0; i<n; ++i) cout<<arr[i]<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
