```cpp
#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout<<#x<<" = "<<x<<'\n'
#define fst first
#define snd second
#define ll long long
const int MAX = 2e5+20;
int t=1, n, r;
string s;

bool Try(string k){
    cout<<"? "<<k<<endl;
    cin>>r;
    return r;
}

void solve(){        
    cin>>n;
    s=(Try("1"))? "1" : "0";
    while(s.size()<n){
        s+="1";
        if(!Try(s)) s.back()='0';
        if(!Try(s)) {s.pop_back(); break;}
    }
    while(s.size()<n){
        s = "1" + s;
        if(!Try(s)) s[0]='0';
    }cout<<"! "<<s<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}
