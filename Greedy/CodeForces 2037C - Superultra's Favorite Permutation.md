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
int t=1, n, arr[MAX], sv[MAX];
set<int> even;

void init(){
    MSET(sv, -1, MAX);
    for(int i = 2; i<MAX; ++i)
        if(sv[i] < 0)
            for(int j = 1LL*i*i; j<MAX && j>=0; j+=i) sv[j] = i;
}

void solve(){        
    cin>>n; even.clear();
    if(n==2 || n==3){cout<<-1<<endl; return;}
    int j=1;
    for(int i=1; i<=n; i+=2) arr[j++]=i;
    for(int i=((n&1)? n-1 : n); i>0; i-=2) even.insert(i);
    bool f=0;
    for(auto i : even) 
        if(sv[arr[j-1]+i]!=-1){
            arr[j]=i;
            even.erase(even.find(i)); 
            f=1;
            break;
        }
    if(!f){cout<<-1<<endl; return;}
    for(auto i : even) arr[++j] = i;
    for(int i=1; i<=n; ++i) cout<<arr[i]<<' '; cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
