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
int t=1, a, b, c;
priority_queue<int, vec<int>, greater<int>> pq;

void solve(){        
    cin>>a>>b>>c;
    while(pq.size()) pq.pop();
    pq.push(a);
    pq.push(b);
    pq.push(c);
    for(int i=0; i<5; ++i) {
        int x = pq.top();
        pq.pop();
        pq.push(x+1);
    }int r = 1; 
    while(pq.size()) r*=pq.top(), pq.pop();
    cout<<r<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
