```cpp
#include <bits/stdc++.h>
using namespace std;


int n, arr[100000];


int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);

    int rslt = n;
    for(int i = 0; i<n; i++) rslt = min(rslt, n-i-1 + arr[i]);
    cout<<rslt<<'\n';
    return 0;

}
