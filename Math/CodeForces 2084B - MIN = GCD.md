```cpp
#include <bits/stdc++.h>
#include <climits>
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
const int MAX = 2e5+20;
ll t=1, n, x;
vec<ll> arr;

bool solve(){        
    cin>>n; arr.resize(n);
    for(auto &i : arr) cin>>i;
    sort(ALL(arr));
    ll mn = arr[0], g=-1, i=1;
    while(i<n) {
        if(!(arr[i]%mn)) {
            g = arr[i];
            break;
        }i++;
    } 
    for(; i<n; ++i) {
        if(g == mn) return 1;
        if(arr[i]%mn) continue;
        g = gcd(g, arr[i]);
    }
    return g == mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
