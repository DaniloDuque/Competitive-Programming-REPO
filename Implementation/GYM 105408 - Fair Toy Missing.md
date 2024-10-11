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
const int MAX = 2e5+20;
int t=1, a[5], b[5];

int solve(){        
    for(int i = 0; i<5; ++i) cin>>a[i];
    for(int i = 0; i<4; ++i) cin>>b[i];
    sort(a, a+5); sort(b, b+4);
    for(int i = 0; i<4; ++i) if(a[i]!=b[i]) return a[i];
    return a[4];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
