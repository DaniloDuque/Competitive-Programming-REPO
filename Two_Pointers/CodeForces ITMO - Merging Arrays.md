```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vec=vector<T>;
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<'\n'
#define CLEAN(arr) (memset(arr, 0, sizeof(arr)))
#define ALL(v) (v).begin(), (v).end()
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20;
int t=1, n, m, a[MAX], b[MAX];
vec<int> c;

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) cin>>a[i];
    for(int i = 0; i<m; ++i) cin>>b[i];
    int i = 0, j = 0;
    while(i<n || j<m){
        if((i<n && a[i]<b[j]) || j>=m) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }for(int &k : c) cout<<k<<' '; cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
