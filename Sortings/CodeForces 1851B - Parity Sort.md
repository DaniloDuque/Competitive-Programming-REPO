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
int t=1, arr[MAX], n, sor[MAX];
map<int, queue<int>> idx;

bool solve(){        
    cin>>n; idx.clear();
    for(int i=0; i<n; ++i) cin>>arr[i];
    for(int i=0; i<n; ++i) sor[i]=arr[i];
    sort(sor, sor+n);
    for(int i=0; i<n; ++i) idx[sor[i]].push(i);
    for(int i=0; i<n; ++i) {
        if(arr[idx[arr[i]].front()]%2 != arr[i]%2) return 0;
        idx[arr[i]].pop();
    }return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<((solve())? "YES" : "NO")<<endl;
    }return 0;
}
