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
int t=1, n, m, L, x, y;
vec<vec<int>> arr;
priority_queue<int> pwu;

void solve(){        
    cin>>n>>m>>L; arr.clear(); 
    while(pwu.size()) pwu.pop();
    for(int i=0; i<n; ++i) cin>>x>>y, arr.push_back({x, y, 1});
    for(int i=0; i<m; ++i) cin>>x>>y, arr.push_back({x, y, 0});
    sort(ALL(arr));
    int r=1;
    for(auto &row : arr){
        int x=row[0], y=row[1];
        if(row[2]){
            while(pwu.size() && r < y-x + 2) r+=pwu.top(), pwu.pop();
            if(r < y-x + 2) {cout<<-1<<endl; return;}
        }else pwu.push(y);
    }cout<<m-pwu.size()<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
