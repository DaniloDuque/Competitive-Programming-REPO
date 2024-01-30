```cpp
#include <bits/stdc++.h>
using namespace std;

long long n, q, arr[200001], x, y;

int main() {

    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i = 1; i<=n; i++) cin>>arr[i];
    sort(arr+1, arr+n+1, greater<int>());
    for(int i = 1; i<=n; i++) arr[i] += arr[i-1];

    while(q--){

        cin>>x>>y;
        cout<<arr[x]-arr[x-y]<<'\n';
        
    }return 0;

}
