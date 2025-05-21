```cpp
#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define SET(m,i) ((m)|(1ULL<<(i)))
#define TEST(m,i) ((m)&(1ULL<<(i)))
#define CLEAR(m,i) ((m)&~(1ULL<<(i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define DEBUG_ALL(a) for(auto &w:a)cout<<w<<' ';cout<<endl;
#define ALLN(x,n) begin(x), begin(x)+n
#define ALL(x) begin(x), end(x)
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const ll MAX = 2e5+20, INF = 1e13;
ll n, k, arr[MAX];
string s;

ll max_sum() {
    ll s=0, mx=0;
    for(auto &i : span(arr, n)) {
        s+=i;
        mx=max(mx, s);
        s=max(s, 0LL);
    }return mx;
}

void result(bool f) {
    if(!f) return void(cout<<"NO"<<endl);
    cout<<"YES"<<endl;
    DEBUG_ALL(span(arr, n));
}

ll sum(ll s, ll e, ll inc) {
    ll sum = 0, cur = 0;
    for(int i=s; i!=e; i+=inc) {
        cur+=arr[i];
        sum=max(cur, sum);
    }return sum;
}

void solve(){        
    cin>>n>>k>>s;
    for(auto &i : span(arr, n)) cin>>i;
    ll mx = max_sum(), c = count(ALL(s), '0');
    if(mx==k) return result(1);
    if(!c) return result(0);
    for(int i=0; i<n; ++i) if(s[i]=='0') arr[i]=-INF;
    if(max_sum()>k) return result(0);
    ll l=-1;
    while(s[l]!='0') l++;
    ll pr = sum(l+1, n, 1), sf = sum(l-1, -1, -1);
    arr[l]=k-pr-sf;
    result(1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
        //cout<<(solve()? "YES" : "NO")<<endl;
    }return 0;
}
