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
const int MAX = 2e5+20;
int t=1, n, k, x, arr[MAX], acc[MAX];
map<int, int> cards;

int sum(int i, int j){return acc[j]-(i>0? acc[i-1] : 0);}

int solve(){        
    cin>>n>>k; cards.clear(); 
    for(int i = 0; i<n; ++i) cin>>x, cards[x]++;
    int max = 0;
    for(auto it = cards.begin(); it!=cards.end();){
        acc[0]=it->snd;
        int m = 1;
        auto nxt = next(it);
        for(;nxt!=cards.end() && (nxt->fst==prev(nxt)->fst+1); ++nxt) acc[m++]=nxt->snd;
        partial_sum(acc, acc+m , acc);
        if(m <= k) max = std::max(max, acc[m-1]);
        else for(int i = 0; i+k-1<m; ++i) max = std::max(max, sum(i, i+k-1)); 
        it = nxt;
    }return max;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
