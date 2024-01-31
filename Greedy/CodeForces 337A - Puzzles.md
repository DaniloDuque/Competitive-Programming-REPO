```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[50];   


int main() {

    ios::sync_with_stdio(0);
    cin>>m>>n;
    for(int i = 0;i<n; i++) cin>>arr[i];
    sort(arr, arr+n);

    int rslt = 1<<30;

    for(int i = 0; i<=n-m; i++)rslt = min(rslt, abs(arr[i]-arr[i+m-1]));
    
    cout<<rslt<<'\n';

    return 0;

}
