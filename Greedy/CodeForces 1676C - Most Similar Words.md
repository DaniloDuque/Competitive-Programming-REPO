```cpp
#include <bits/stdc++.h>
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
const int MAX = 5e1+1;
int t=1, n, m;
string arr[MAX];

int diff(string &a, string &b){
    int d = 0;
    for(int i = 0; a[i]; ++i) d += abs(a[i]-b[i]);
    return d;
}

void solve(){        
    cin>>n>>m;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int min = INT_MAX;
    for(int i = 0; i<n; ++i)
        for(int j = i+1; j<n; ++j)
            min = std::min(min, diff(arr[i], arr[j]));
    cout<<min<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
