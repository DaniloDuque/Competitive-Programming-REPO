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
const int MAX = 2e3, MOD = 1e9+7;
int t=1, n, arr[MAX], d, s;
priority_queue<int, vec<int>, greater<int>> pq;

void solve(){        
    cin>>n; MSET(arr, MOD, MAX);
    while(pq.size()) pq.pop();
    for(int i=0; i<n; ++i) cin>>d>>s, arr[d]=min(arr[d], s);
    int k=1;
    for(int i=1; i<MAX; ++i) {
        if(arr[i]!=MOD) pq.push(arr[i]+1);
        if(pq.empty()){k++; continue;}
        int c = pq.top()-2; pq.pop();
        if(c<=1) break;
        k++;
        pq.push(c);
    }cout<<k<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
