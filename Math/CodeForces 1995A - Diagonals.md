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
int t=1, n, k;

int solve(){        
    cin>>n>>k;
    int r = 1;
    if(!k) return k;
    if(n >= k) return 1;
    k-=n;
    for(int i = n-1; k>0; --i){
        if(i>=k) return r+1; 
        if(i*2>=k) return r+2;
        k-=2*i;
        r+=2;
    }return r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
