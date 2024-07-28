```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, x, dp[(int)2e5+20];
map<int, vector<int> > m;


int dpp(int num = 0, int i = 0, int j = 0){
    if(num == n) return 0;
    if(dp[i] != -1) return dp[i];
    ++num;
    return dp[i] = min(abs(i - m[num][0]) + abs(j - m[num][1]) + dpp(num, m[num][0], m[num][1]), 
                    abs(i - m[num][1]) + abs(j - m[num][0]) + dpp(num, m[num][1], m[num][0]));
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i<2*n; i++){
        cin>>x;
        if(m.find(x) == m.end()) m.insert(make_pair(x, vector<int>(1, i)));
        else m[x].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    cout<<dpp()<<endl;
    return 0;
}

