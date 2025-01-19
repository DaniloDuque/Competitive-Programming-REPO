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
#define pi pair<char, int>
const int Max = 2e5+20, MOD = 1e9+7;
int t=1, n, chrs[27];
string s;
map<char, int> mp;

bool cmp(const pi &a, const pi &b){
    return a.snd < b.snd;
}

void solve(){        
    cin>>n>>s; mp.clear();
    for(char &c : s) mp[c]++;
    pi Max = *max_element(ALL(mp), cmp);
    mp.erase(Max.fst);
    if(mp.empty()){cout<<s<<endl; return;}
    pi Min = *min_element(ALL(mp), cmp);
    //DEBUG(Max.fst); DEBUG(Min.fst);
    for(int i=0; s[i]; ++i)
        if(s[i]==Min.fst){
            s[i]=Max.fst; 
            break;
        }
    cout<<s<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
