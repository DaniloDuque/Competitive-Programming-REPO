```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int t, n, m, k, w, gs[(int)2e5+1];
vector<int> r;

signed main(){

    scanf("%lld", &t);
    while(t--){
        
        scanf("%lld %lld %lld %lld", &n, &m, &k, &w);
        for(int i = 0; i<w;) scanf("%lld", &gs[i++]);
        sort(gs, gs+w, greater<int>()); r.clear();
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j)
                r.push_back((min(j, m-k) - max(0LL, j-k+1) + 1) * (min(i, n-k) - max(0LL, i-k+1) + 1));

        int sum = 0; sort(r.rbegin(), r.rend());
        for(int i = 0; i<w; ++i) sum += r[i]*gs[i];
        printf("%lld\n", sum);

    }return 0;

}
