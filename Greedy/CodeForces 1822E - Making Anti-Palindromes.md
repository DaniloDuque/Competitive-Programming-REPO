```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
#define pb push_back
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, n;
string s;
map<char, int> cnt;

void solve(){        
    cin>>n>>s; cnt.clear();
    if(n&1) {cout<<-1<<endl; return;}
    for(auto &c : s) cnt[c]++;
    int max=0; char c;
    for(auto &[x, y] : cnt) if(max < y) c=x, max=y; 
    if(cnt[c]*2 > n) {cout<<-1<<endl; return;}
    cnt.clear();
    string l=s.substr(0, n/2), r=s.substr(n/2, n);
    reverse(ALL(r));
    int prob=0;
    for(int i=0; l[i]; ++i) prob+=l[i]==r[i], cnt[l[i]]+=(l[i]==r[i]);
    max = 0;
    for(auto &[x, y] : cnt) max = std::max(max, y);
    cout<<std::max(max, (prob+1)/2)<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
