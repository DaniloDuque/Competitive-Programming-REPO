```cpp
#include <bits/stdc++.h>
using namespace std;

int sz, m, arr[(1<<17) + 20], p, b;

struct STree { // segment tree for OR and XOR operations

    vector<int> st;
    int n;
    STree(int n): st(4*n+5), n(n) {}
    
    void init(int k, int s, int e, int *a, int l){
        if(s+1 == e) {st[k] = a[s];return;}
        int m = (s+e)>>1;
        init(2*k, s, m, a, l-1); init(2*k+1, m, e, a, l-1);
        st[k] = (l&1) ? (st[2*k] ^ st[2*k+1]) : (st[2*k] | st[2*k+1]);
    }

    void upd(int k, int s, int e, int p, int v, int l){
        if(s+1 == e) {st[k] = v;return;}
        int m = (s+e)>>1;
        if(p < m) upd(2*k, s, m, p, v, l-1);
        else upd(2*k+1, m, e, p, v, l-1);
        st[k] = (l&1) ? (st[2*k] ^ st[2*k+1]) : (st[2*k] | st[2*k+1]);
    }

    int query() {
        return st[1]; 
    }

    void init(int *a){ init(1, 0, n, a, sz-1); }
    void upd(int p, int v){ upd(1, 0, n, p, v, sz-1); }

};

int main(){

    scanf("%d %d", &sz, &m);
    for(int i = 0; i < 1<<sz; i++) scanf("%d", &arr[i]);
    STree rmq(1<<sz); rmq.init(arr);

    while(m--){
        scanf("%d %d", &p, &b);
        rmq.upd(--p, b);
        printf("%d\n", rmq.query());

    }return 0;

}
