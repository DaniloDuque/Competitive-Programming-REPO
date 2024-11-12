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
int t=1, n, arr[MAX];
set<int> act, lft;
vec<int> days;

bool possible(){
    for(int i=0; i<n; ++i){
        if(arr[i]<0){
            if(!act.count(arr[i])) return 0;
            act.erase(arr[i]); lft.insert(-arr[i]);
            if(act.empty()) days.push_back(i), lft.clear();
        }else if(act.count(-arr[i]) || lft.count(arr[i])) return 0; 
        else act.insert(-arr[i]);
    }return act.empty();
}

void solve(){        
    cin>>n;
    for(int i=0; i<n; ++i) cin>>arr[i];
    if(!possible()) {cout<<"-1\n"; return;}
    cout<<days.size()<<'\n';
    cout<<days[0]+1<<' ';
    for(int i=1; i<days.size(); ++i){
        cout<<days[i]-days[i-1]<<' ';
    }cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }return 0;
}
