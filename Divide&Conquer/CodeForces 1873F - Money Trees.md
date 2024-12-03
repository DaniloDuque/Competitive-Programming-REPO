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
int t=1, n, k, arr[MAX], h[MAX], len[MAX];

int binarySearch(int l, int r) {
    int st = l;
    while(r>=l){
        int m = (l+r)>>1;
        if(arr[m]-arr[st-1] > k) r=m-1;
        else l=m+1;
    }return l-st;
}

void solve(){        
    cin>>n>>k;
    for(int i=1; i<=n; ++i) cin>>arr[i];
    for(int i=1; i<=n; ++i) cin>>h[i];
    partial_sum(arr, arr+n+1, arr);
    len[n]=1;
    for(int i=n-1; i>0; --i) len[i] = (h[i]%h[i+1])? 1 : len[i+1]+1;
    int rs = 0;
    for(int i=1; i<=n; ++i) rs = max(rs, binarySearch(i, i+len[i]-1));
    cout<<rs<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
