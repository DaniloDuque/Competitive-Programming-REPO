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
int t=1, k, n;

string solve(){        
    cin>>k>>n;
    if(k > (n+1)/2) return "*";
    string r = "";
    int m = n;
    while(k>0 && m/k > 0){
        if(m/k > 2) r+="-X-", m-=3;
        else r+="X-", m-=2;
        k--;
    }
    return (r.size() < n)? "*" : r.substr(0, n);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
