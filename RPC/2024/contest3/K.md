```cpp
#include <bits/stdc++.h>
using namespace std;



#define isVoc(c) ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U') || (c == 'Y'))
#define oo (1L<<30)
#define int long
int n;
vector<string> phrs;
vector<vector<int>> dp;



int dist(string &s){
    for(int i = 0; i<min((int) s.size(), 3L); ++i) 
        if(isVoc(s[i])) return i;
    return oo;
}



int minAcro(int i, int prv){

    if(prv > 2) return oo;
    if(i == n) return 0;
    int &mem = dp[i][prv], d = dist(phrs[i]);
    if(mem != -1) return mem;
    return mem = 1 + min(d + minAcro(i+1, (d + prv < 3)? 0: oo), minAcro(i+1, prv+1));

}



signed main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n; phrs.assign(n, ""); dp.assign(n, {-1, -1, -1});
    for(int i = 0; i<n; ++i) cin>>phrs[i];
    (minAcro(0, 0) >= oo)? cout<<"*\n" : cout<<minAcro(0, 0)<<'\n';
    return 0;

}
