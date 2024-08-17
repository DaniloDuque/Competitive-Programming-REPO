```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vvi vector<vector<int>>
#define MAX (int)2e5+1

int t, n, m, x;
vector<vector<int>> a, b, sa, sb;
bool flag;
bitset<MAX> vstA, vstB;

bool eqlRow(int i, int j){
    vstA.reset(), vstB.reset();
    for(int k = 0; k<m; ++k) vstA.set(a[i][k]), vstB.set(b[j][k]);
    return vstA == vstB;
}

bool eqlColumn(int i, int j){
    vstA.reset(), vstB.reset();
    for(int k = 0; k<n; ++k) vstA.set(a[k][i]), vstB.set(b[k][j]);
    return vstA == vstB;
}   

vvi sum(vvi &x){
    vvi s(max(n, m), {0, 0});
    for(int i = 0; i<n; ++i)
        for(int j = 0; j<m; ++j) 
            s[i][0] += x[i][j];
    for(int i = 0; i<m; ++i)
        for(int j = 0; j<n; ++j)
            s[i][1] += x[j][i];
    return s;
}

bool possible(){

    for(int i = 0; i<n; ++i){
        flag = 0;
        for(int j = 0; j<n && !flag; ++j) if(sa[i][0] == sb[j][0] && eqlRow(i, j)) flag = 1; 
        if(!flag) return 0;
    }
    for(int i = 0; i<m; ++i){
        flag = 0; 
        for(int j = 0; j<m && !flag; ++j) if(sa[i][1] == sb[j][1] && eqlColumn(i, j)) flag = 1;
        if(!flag) return 0;
    }
    return 1;

}


signed main(){

    scanf("%lld", &t);
    while(t--){
    
        scanf("%lld %lld", &n, &m);
        a.assign(n, {}), b.assign(n, {});
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j)
                scanf("%lld", &x), a[i].push_back(x);
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j)
                scanf("%lld", &x), b[i].push_back(x);
        sa = sum(a), sb = sum(b);
        puts((n == 1 || m == 1 || possible())? "YES" : "NO");

    }return 0;

}
