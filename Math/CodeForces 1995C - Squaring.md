```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define eps 1e-9
#define ll long long
#define ld long double
const int MAX = 2e5+20;
int t=1, n;
ld arr[MAX], m;

ll solve(){        
    cin>>n; m = 0;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    for(int i = 0; i<n; ++i){
        m=max(m, arr[i]);
        if(m>1 && arr[i]==1) return -1;
    }
    int s = 0;
    while(arr[s]==1) ++s;
    for(int i = s; i<n; ++i) arr[i]=log2(log2(arr[i]));
    ll rslt = 0;
    for(int i = s+1; i<n; ++i){
        ld diff = arr[i-1]-arr[i];
        if(diff > eps){
            ll nxt = 1 + (diff-eps);
            rslt+=nxt;
            arr[i]+=nxt;
        }
    }return rslt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
