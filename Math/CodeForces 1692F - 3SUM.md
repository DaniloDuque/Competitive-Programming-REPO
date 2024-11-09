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
const int MAX = 4e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX], mod[10];

bool solve(){        
    cin>>n; MSET(mod, 0, 10);
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i=0; i<n; ++i) mod[arr[i]%10]++;
    for(int i = 0; i<10; ++i){
        if(!mod[i]) continue;
        int x = ((3-i)%10 + 10)%10;
        mod[i]--;
        for(int j=0; j<10; ++j){
            if(!mod[j]) continue;
            mod[j]--;
            if(mod[((x-j)%10 + 10)%10]) return 1;
            mod[j]++;
        }mod[i]++;
    }return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<((solve())? "YES" : "NO")<<'\n';
    }return 0;
}
