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
int t=1, arr[10][10];
string mat[10];

void solve(){        
    for(int i=0; i<10; ++i) cin>>mat[i];
    int k=0;
    for(int i=0; i<10; ++i)
        for(int j=0; j<10; ++j)
            if(mat[i][j]=='X') k+=arr[i][j];
    cout<<k<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=1; i<=5; ++i)for(int j=i-1; j<=10-i; ++j) arr[i-1][j]=arr[j][i-1]=arr[j][10-i]=arr[10-i][j]=i;
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
