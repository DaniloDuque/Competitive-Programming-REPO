```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 2e5 + 20;
int t, n, a[MAX], p;
vector<vector<int>> Tree;

int dfs(int i){
    
    if(!Tree[i].size()) return a[i];
    int min = UINT_MAX;
    for(int &j : Tree[i]) min = std::min(min, dfs(j));
    return a[i] = (!i)? a[i]+min : std::min(min, (a[i] + min)>>1);

}

signed main(){

    scanf("%lld", &t);
    while(t--){
        
        scanf("%lld", &n); Tree.assign(n, {});
        for(int i = 0; i<n;) scanf("%lld", &a[i++]);
        for(int i = 1; i<n;){ scanf("%lld", &p); Tree[--p].push_back(i++);}
        printf("%lld\n", max(a[0], dfs(0)));

    }return 0;

}
