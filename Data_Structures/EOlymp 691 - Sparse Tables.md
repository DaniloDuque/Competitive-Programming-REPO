```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define K 17 
#define MOD 16714589
int spt[K][1<<K], n, m, arr[(int)1e5+10], u, v; // -> 2^K > n

void init(int *a){
    for(int i = 0; i<n; ++i) spt[0][i] = a[i];
    for(int k = 1; k<K; ++k)
        for(int i = 0; i<=n-(1<<k); ++i)
            spt[k][i] = min(spt[k-1][i], spt[k-1][i+(1<<(k-1))]);
}

int query(int i, int j){
    if(i > j) swap(i, j);
    int k = 31-__builtin_clz(j-i);
    return min(spt[k][i-1], spt[k][j-(1<<k)]);
}

signed main(){
    
    scanf("%lld %lld %lld", &n, &m, &arr[0]);
    for(int i = 1; i<n; ++i) arr[i] = (23*arr[i-1]+21563)%MOD; 
    init(arr);
    scanf("%lld %lld", &u, &v);
    for(int i = 1; i<m; ++i){
        int q = query(u, v);
        u = ((17*u+751+q+2*i)%n)+1; 
        v = ((13*v+593+q+5*i)%n)+1;
    }printf("%lld %lld %lld\n", u, v, query(u, v));
    return 0;

}
