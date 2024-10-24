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
const int MAX = 1e6+20, MOD = 1e9+7;
int t=1, n, arr[MAX], inv[MAX], m1[MAX], m2[MAX];

int solve(){        
    cin>>n; 
    for(int i = 0; i<n; ++i) cin>>arr[i], --arr[i]; 
    for(int i = 0; i<n; ++i) inv[i] = arr[arr[i]];
    for(int i = 0; i<n; ++i) m1[arr[i]]=i, m2[inv[i]]=i;
    int r1 = 0, r2 = 0;
    for(int i = 0; i<n; ++i)
        if(arr[i]!=i){
            r1++;
            int c = arr[i];
            arr[i]=i;
            arr[m1[i]]=c;
            m1[c]=m1[i];
            m1[i]=i;
        } 
    for(int i = 0; i<n; ++i)
        if(inv[i]!=i){
            r2++;
            int c = inv[i];
            inv[i]=i;
            inv[m2[i]]=c;
            m2[c]=m2[i];
            m2[i]=i;
        }
    return min(r1, r2)>>1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
