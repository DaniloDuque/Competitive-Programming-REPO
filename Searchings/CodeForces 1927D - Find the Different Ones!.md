```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, q, arr[200001], Q[200001], r, m ;


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 0;i<n; i++) cin>>arr[i];

        Q[0] = 0;
        for(int i = 1; i<n; i++) Q[i] = Q[i-1] + (arr[i] != arr[i-1]);
            
        cin>>q;
        while(q--){

            cin>>r>>m;
            int j = lower_bound(Q, Q+n, Q[r-1]+1)-Q;
            (j == Q[r-1] || j >= m)? cout<<"-1 -1\n":  cout<<r<<' '<<j+1<<'\n';

        }cout<<'\n';


    }return 0;

}
