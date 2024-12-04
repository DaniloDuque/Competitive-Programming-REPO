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
const int MAX = 1e3, MOD = 1e9+7;
ll t=1, a, b, arr[MAX];

void solve(){        
    cin>>a>>b;
    for(int i=0; i<MAX; ++i) arr[i]=b;
    int mean = a*MAX, sum = accumulate(arr, arr+MAX, 0);
    arr[MAX-1]+=mean-sum;
    sort(arr, arr+MAX);
    cout<<MAX<<endl;
    for(int i=0; i<MAX; ++i) cout<<arr[i]<<' '; cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
