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
int t=1, q, x, y, exists=0;
string s;
vec<string> arr;

string substr(string &a, int i, int j){
    string r = "";
    for(; i<j; ++i) r+=a[i];
    return r;
}

void solve(){        
    cin>>s>>q; arr.clear(); exists=0;
    for(int i=0; i+4<=s.size(); ++i) arr.push_back(substr(s, i, i+4));
    for(auto &k : arr) if(k=="1100") exists++;
    while(q--){
        cin>>x>>y;
        x--;
        s[x]=y+'0';
        for(int i = max(0, x-3); i<=min(x+3,(int)arr.size()-1); ++i){
            //DEBUG(i);
            if(arr[i]=="1100") exists--;
            arr[i]=substr(s, i, i+4);
            if(arr[i]=="1100") exists++;
        }
        cout<<((exists)? "YES" : "NO")<<'\n';
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
