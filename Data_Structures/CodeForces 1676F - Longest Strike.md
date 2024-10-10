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
int t=1, n, k, arr[MAX];
map<int, int> reps;

void solve(){        
    cin>>n>>k; reps.clear();
    for(int i = 0; i<n; ++i) cin>>arr[i], reps[arr[i]]++;
    int l, r, max = 0;
    for(auto it = reps.begin(); it!=reps.end(); ++it){
        if(it->snd<k) continue;
        int m = 1, i = 0;
        while(reps[it->fst+i]>=k) i++;
        if(i > max) max = i, l = it->fst, r = it->fst+i-1;
        while(i--) it++;
    }(!max)? cout<<-1 : cout<<l<<' '<<r;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
