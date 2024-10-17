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
const int MAX = 33, MOD = 1e9+7;
int t=1, n;
char c;
string s;
map<char, vec<int>> cards;
vec<int> trumps;
vec<char> erase;

void play(char k){
    vec<int> &curr = cards[k];
    sort(ALL(curr));
    for(int i = 0; i<curr.size()-1; i++, ++i) cout<<curr[i]<<k<<' '<<curr[i+1]<<k<<'\n';
    if(curr.size()&1) curr = {curr.back()};
    else erase.push_back(k);
}

void solve(){        
    cin>>n>>c; int miss = 0, k = 0; 
    trumps.clear(); cards.clear(); erase.clear();
    for(int i = 0; i<2*n; ++i){
        cin>>s;
        cards[s[1]].push_back(s[0]-'0');
        if(s[1]==c) trumps.push_back(s[0]-'0');
    }
    for(auto &v : cards) if(v.fst!=c) miss += v.snd.size()&1;
    if(miss > trumps.size()) {cout<<"IMPOSSIBLE\n"; return;}
    for(auto &v : cards) if(v.fst!=c) play(v.fst);
    for(char &a : erase) cards.erase(a);
    sort(ALL(trumps));
    for(auto &v : cards) if(v.fst!=c && v.snd.size()) cout<<v.snd[0]<<v.fst<<' '<<trumps[k++]<<c<<'\n';
    for(;k+1<trumps.size(); k+=2) cout<<trumps[k]<<c<<' '<<trumps[k+1]<<c<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
