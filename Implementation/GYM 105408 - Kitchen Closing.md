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
const int MAX = 110;
int t=1, n, m, o, qnt[MAX], m_i, I, Q, order[MAX], d_i, dishes[MAX][MAX];

int solve(){        
    int rslt = 0;
    cin>>n>>m>>o;
    for(int i = 0; i<n; ++i) cin>>qnt[i];
    for(int j = 0; j<m; ++j){
        cin>>m_i;
        while(m_i--){
            cin>>I>>Q;
            dishes[j][I-1]+=Q;
        }
    }
    while(o--){
        cin>>m_i;
        while(m_i--){
            cin>>d_i; --d_i;
            for(int i=0; i<MAX; ++i){
                if(dishes[d_i][i] > qnt[i]) return rslt; 
                qnt[i]-=dishes[d_i][i];
            }
        }rslt++;
    }return rslt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        cout<<solve()<<'\n';
    }return 0;
}
