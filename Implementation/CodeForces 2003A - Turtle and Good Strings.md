```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

bool valid(string &a, string &b){
    for(int i = 0; i<a.size(); ++i)
        for(int j = i; j<b.size() ; ++j)
            if(a[i] == b[j]) return 0;
    return 1;
}

bool sol(){
    for(int k = 2; k<=n; ++k){
        string a, b;
        for(int i = 0; i*k<n; ++i) a.push_back(s[i*k]);
        for(int i = 1; i*k-1<n; ++i) b.push_back(s[i*k-1]);
        b.push_back(s.back());
        if(valid(a, b)) return 1;
    }return 0;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>s;
        cout<<(sol()? "YES" : "NO")<<'\n';
    }return 0;

}
