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
int t=1, k, arr[MAX];
map<int, int> cnt;

void solve(){        
    cin>>k; cnt.clear();
    for(int i=0; i<k; ++i) cin>>arr[i];
    for(int i=0; i<k; ++i) cnt[arr[i]]++;
    int a = k-2;
    for(int i=1; i<=a; ++i) 
        if(i*(a/i) == a && cnt.count(i) && cnt.count(a/i)){ 
            if(a/i == i && cnt[i] < 2) continue;
            cout<<i<<' '<<a/i<<endl;
            return;
        }
    cout<<-1<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
