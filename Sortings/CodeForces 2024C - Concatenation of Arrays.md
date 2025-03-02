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
int t=1, n;
pair<int, int> arr[MAX];

bool cmp(pair<int, int> &a, pair<int, int> &b){
    double p1 = (a.fst+a.snd)/2.0;
    double p2 = (b.fst+b.snd)/2.0;
    return p1 < p2;
}

void solve(){        
    cin>>n;
    for(int i = 0; i<n; ++i) cin>>arr[i].fst>>arr[i].snd;
    sort(arr, arr+n, cmp);
    for(int i = 0; i<n; ++i) cout<<arr[i].fst<<' '<<arr[i].snd<<' ';
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
