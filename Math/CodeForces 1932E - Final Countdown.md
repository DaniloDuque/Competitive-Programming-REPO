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
const int MAX = 4e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX];
string s;

void solve(){        
    cin>>n>>s;
    arr[0] = s[0]-'0';
    for(int i = 1; i<n; ++i) arr[i]=arr[i-1]+(s[i]-'0'); 
    vec<int> rslt;
    for(int i = n-1; i>0; --i){
        rslt.push_back(arr[i]%10);
        arr[i]/=10;
        arr[i-1]+=arr[i];
    }rslt.push_back(arr[0]);
    while(rslt.size()>1 && rslt.back()==0) rslt.pop_back();
    reverse(ALL(rslt));
    for(int &i : rslt) cout<<i;
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
