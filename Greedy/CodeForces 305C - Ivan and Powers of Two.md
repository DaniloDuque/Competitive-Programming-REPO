```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long
int n, x, a[(int)1e5+20];
priority_queue<int, vector<int>, greater<int> > pq;

signed main(){

    scanf("%ld", &n);
    for(int i = 0; i<n; ++i) scanf("%ld", &a[i]);
    for(int k = 0; k<32; ++k){
        for(int i = 0; i<n-1; ++i) if(a[i] == a[i+1]) a[i+1]++; else pq.push(a[i]);
        pq.push(a[n-1]); n = pq.size();
        for(int i = 0; !pq.empty(); ++i) a[i] = pq.top(), pq.pop(); 
    }
    printf("%ld\n", a[n-1]-n+1);
    return 0;

}
