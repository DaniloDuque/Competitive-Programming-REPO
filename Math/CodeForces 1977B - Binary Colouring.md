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
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
ll t=1, x;

void solve(){        
    cin>>x;
    vec<int> msk(32, 0);
    for(int i=0; i<32; ++i) if(TEST(x, i)) msk[i]=1;
    for(int i=0; i<31; ++i) {
        if(msk[i] && msk[i+1]) {
            int j=i+1; 
            while(j<31 && msk[j]) j++;
            msk[i]=-1;
            for(int k=i+1; k<j; ++k) msk[k]=0;
            msk[j]=1;
            i=j-1;
        }
    }cout<<32<<endl;
    for(auto &i : msk) cout<<i<<' '; cout<<endl; 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
