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
#define ps pair<string, string>
const int MAX = 1e5+20;
int t=1, n, q;
string s;
ps arr[MAX];

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) {cin>>s; arr[i]={s, s}; sort(ALL(arr[i].fst));}
    sort(arr, arr+n);
    cin>>q;
    while(q--){
        cin>>s;
        string sorted = s; sort(ALL(sorted));
        ps curr = {sorted, s};
        cout<<lower_bound(arr, arr+n, curr)-arr<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
