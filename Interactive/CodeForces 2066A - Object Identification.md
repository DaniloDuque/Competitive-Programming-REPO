```cpp
#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define pb push_back
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
ll n, q, q1, q2;
vec<ll> arr;
set<ll> st;

string solve(){        
    cin>>n; arr.resize(n); st.clear();
    for(int i=1; i<=n; ++i) st.insert(i);
    for(auto &i : arr) cin>>i, st.erase(i);
    if(st.size()) {
        cout<<"? "<<*st.begin()<<' '<<arr[0]<<endl;
        cin>>q;
        return q? "! B" : "! A";
    }
    ll x, y, mx=-1, mn=INT_MAX;
    for(int i=0; i<n; ++i) {
        if(arr[i]<mn) y=i+1, mn=arr[i];
        if(arr[i]>mx) x=i+1, mx=arr[i];
    }
    cout<<"? "<<x<<' '<<y<<endl;
    cin>>q1;
    cout<<"? "<<y<<' '<<x<<endl;
    cin>>q2;
    return (q1<n-1 || q1!=q2)? "! A" : "! B";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }return 0;
}
