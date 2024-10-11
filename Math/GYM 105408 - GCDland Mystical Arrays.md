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
const int MAX = 1e7+1;
int t=1, n, sv[MAX], arr[(int)1e5+2];
set<int> fcts;

void init(){
    memset(sv, -1, sizeof(sv));
    for(int i = 2; i<MAX; ++i)
        if(sv[i] < 0)
            for(ll j = 1LL*i*i; j<MAX; j+=i) sv[j] = i;
}

map<int, int> factorize(int n){
    map<int, int> r;
    while(sv[n] >= 0) ++r[sv[n]], n/=sv[n];
    if(n>1) r[n]++;
    return r;
}

bool solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    int g = gcd(arr[0], arr[1]);
    for(int i = 0; i<n; ++i){
        if(arr[i]%g) return 0;
        arr[i]/=g;
        for(auto p : factorize(arr[i])){
            if(fcts.count(p.fst)) return 0;
            fcts.insert(p.fst);
        }
    }return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    while(t--){
        cout<<((solve())? "YES" : "NO")<<'\n';
    }return 0;
}
