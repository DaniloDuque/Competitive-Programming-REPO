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
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, k;
vec<ll> arr;

pair<ll, ll> calc(int a, int b, int inc){
    ll c=0, cnt=0, lst=0, idx=-1;
    for(int i=a; i!=b; i+=inc) {
        if(arr[i]<=k) cnt++, lst++;
        if(cnt>abs(i-a)/2 && lst) c++, lst=0;
        if(cnt>abs(i-a)/2 && idx==-1) idx=i;
    }return {c, idx};
}

bool solve(){        
    cin>>n>>k; arr.resize(n);
    for(auto &i : arr) cin>>i;
    auto [l, i] = calc(0, n, 1);
    auto [r, j] = calc(n-1, -1, -1);
    if(r>1 || l>1) return 1;
    if(!r || !l) return 0;
    return j>i; 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
