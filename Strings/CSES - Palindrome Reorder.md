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
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1, mp[27];
string s;
vec<pair<int, char>> cnt;
 
string solve(){        
    cin>>s;
    for(auto &c : s) mp[c-'A']++;
    for(int i=0; i<27; ++i) if(mp[i]) cnt.emplace_back(mp[i], i+'A');
    sort(ALL(cnt));
    for(auto &[x, y] : cnt) {
        if(x%2==0) continue;
        s[s.size()/2]=y;
        x--;
        break;
    }int i=0, j=s.size()-1;
    for(int k=0; i<j && k<cnt.size();) {
        if(cnt[k].fst & 1) return "NO SOLUTION";
        if(!cnt[k].fst) {k++; continue;}
        cnt[k].fst-=2;
        s[i++]=s[j--]=cnt[k].snd;
    }return s;
}
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
