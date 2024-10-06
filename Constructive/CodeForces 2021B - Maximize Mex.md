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
int t=1, n, x, arr[MAX], mex[MAX];

void solve(){        
    cin>>n>>x;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n; ++i){ 
        int j = (arr[i] < n)? mex[arr[i]] : 1;
        while(arr[i]<n && mex[arr[i]]) arr[i]+=x*j;
        if(arr[i]<n) mex[arr[i]]++;
    }
    int m = 0;
    while(mex[m]) ++m;
    cout<<m<<'\n';
    for(int i=0; i<n; ++i) mex[i]=0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
