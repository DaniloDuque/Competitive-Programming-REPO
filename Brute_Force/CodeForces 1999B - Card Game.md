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
int t=1, arr[4];

int cmp(int i, int j){
    int a = arr[i], b = arr[j];
    return (a>b)? 1 : (a==b)? 0 : -1; 
}

int f(int a, int b, int i, int j){
    return (cmp(a, b)+cmp(i, j))>0;
}

void solve(){        
    for(int i = 0; i<4; ++i) cin>>arr[i];
    int rslt = f(0, 2, 1 ,3) + f(0, 3, 1, 2) + f(1, 2, 0, 3) +  f(1, 3, 0, 2);
    cout<<rslt<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
