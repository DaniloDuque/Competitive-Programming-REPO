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
int t=1, n;
const string mx = "zzzz";

string BT(int i, string s, int sum = 0){
    if(i>3 && sum>n) return mx;
    if(i==3) return (sum==n)? s : mx;
    string rslt = mx;
    for(int j=0; j<26; ++j) rslt = min(rslt, BT(i+1, s + char(j+'a'), sum+j+1));
    return rslt;
}

void solve(){        
    cin>>n;
    cout<<BT(0, "")<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
