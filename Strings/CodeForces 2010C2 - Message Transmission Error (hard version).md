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
int t=1;
string s;

vec<int> kmppre(string& t){ 
    vec<int> r(t.size()+1);
    r[0] = -1;
    int j = -1;
    for(int i = 0; t[i]; i++){
        while(j >= 0 && t[i] != t[j]) j = r[j];
        r[i+1] = ++j;
    }return r;
}

void solve() {
    cin>>s;
    vector<int> pi = kmppre(s);
    int n = s.size(), k = pi.back();
    if(k > n/2) cout<<"YES\n"<<s.substr(0, k);
    else cout<<"NO";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }return 0;
}
