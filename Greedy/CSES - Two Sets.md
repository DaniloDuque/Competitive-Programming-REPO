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
const int MAX = 1e6+20, MOD = 1e9+7;
ll t=1, n;
bitset<MAX> v;
vec<int> s1, s2;

void solve(){        
    cin>>n;
    if((n*(n+1)/2) % 2) {cout<<"NO"<<endl; return;}
    ll obj = n*(n+1)/4, r = n, sum = 0;
    while(sum < obj) {
        ll diff = obj - sum;
        if(diff > r) {
            s1.push_back(r);
            v.set(r);
            sum+=r--;
        } else {
            s1.push_back(diff);
            v.set(diff);
            sum = obj;
        }
    }for(int i=1; i<=n; ++i) if(!v.test(i)) s2.push_back(i);
    cout<<"YES\n"<<s1.size()<<endl;
    for(auto &i : s1) cout<<i<<' '; cout<<endl;
    cout<<s2.size()<<endl;
    for(auto &i : s2) cout<<i<<' '; cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
