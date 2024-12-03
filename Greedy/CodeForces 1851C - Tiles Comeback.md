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
int t=1, n, k, arr[MAX];
map<int, int> clrs;

bool solve(){        
    cin>>n>>k; clrs.clear();
    for(int i=0; i<n; ++i) cin>>arr[i], clrs[arr[i]]++;
    if(arr[0]==arr[n-1] && clrs[arr[0]] >= k) return 1;
    int r=0, i=0, x=0;
    for(;i<n && r<k; i++) r+=(arr[i]==arr[0]);
    if(r<k || i==n) return 0;
    for(int j=i; j<n; j++) x+=(arr[j]==arr[n-1]);
    if(x<k) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
