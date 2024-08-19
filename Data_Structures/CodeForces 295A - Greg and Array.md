```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 1e5+20;
int n, m, k, diffQ[MAX], diff[MAX], arr[MAX], qs[3][MAX], x, y; 

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 0; i<n; ++i) cin>>arr[i];
    diff[0] = arr[0];
    for(int i = 1; i<n; ++i) diff[i] = arr[i]-arr[i-1];
    for(int i = 0; i<m; ++i) cin>>qs[0][i]>>qs[1][i]>>qs[2][i];
    for(int i = 0; i<k; ++i) cin>>x>>y, ++diffQ[x-1], --diffQ[y];
    partial_sum(diffQ, diffQ+m, diffQ);
    for(int i = 0; i<m; ++i){
        int d = qs[2][i]*diffQ[i];
        diff[qs[0][i]-1] += d;
        diff[qs[1][i]] -= d;
    }partial_sum(diff, diff+n, diff);
    for(int i = 0; i<n; ++i) cout<<diff[i]<<' '; cout<<'\n';
    return 0;

}
