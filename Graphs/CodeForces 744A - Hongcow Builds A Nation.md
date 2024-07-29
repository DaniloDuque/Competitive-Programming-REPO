```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, k, x, y, uf[1001], sizeds[1001];
vector<set<int>> G;
vector<int> spec;

int Find(int i){
    return (uf[i] == i)? i : uf[i] = Find(uf[i]);
}

void Union(int x, int y){
    int i = Find(x), j = Find(y);
    if(i == j) return;
    uf[i] = j;
}

int Gauss(int i){
    return (i*(i-1))/2;
}
signed main(){
    
    scanf("%lld %lld %lld", &n, &m, &k);
    G.assign(n, {}); iota(uf, uf+n, 0);
    for(int i = 0; i<k; i++){
        scanf("%lld", &x);
        spec.push_back(x-1);
    }
        
    for(int i = 0; i<m; ++i){
        scanf("%lld %lld", &x, &y);
        G[--x].insert(--y);
        G[y].insert(x);
    }

    for(int i = 0; i<n; ++i)
        for(int j : G[i])
            Union(i, j);
    
    for(int i = 0; i<n; ++i) sizeds[Find(i)]++;
    int left = n, rslt = 0, large = 0;
    for(int i : spec){
        large = max(large, sizeds[Find(i)]);
        rslt += Gauss(sizeds[Find(i)]);
        left -= sizeds[Find(i)];
    }
    
    printf("%lld\n", rslt - Gauss(large) + Gauss(large + left) - m);
    return 0;

}
