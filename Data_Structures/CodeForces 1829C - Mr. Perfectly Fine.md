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
int t=1, n, x; 
string s;
set<int> l, r, b;

int best(){
    int cur = INT_MAX;
    if(b.size()) cur = *b.begin();
    if(r.size() && l.size()) cur = min(cur, (*r.begin())+(*l.begin()));
    return cur;
}

void solve(){        
    cin>>n; l.clear(); r.clear(); b.clear();
    for(int i = 0; i<n; ++i){
        cin>>x>>s;
        if(s=="01") r.insert(x);
        else if(s=="10") l.insert(x);
        else if(s=="11") b.insert(x);
    }
    if(b.empty() && (r.empty() || l.empty())) cout<<-1;
    else cout<<best();
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
