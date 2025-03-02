```cpp
#include <bits/stdc++.h>
using namespace std;

int n, arr[100];


int main() {

    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    cout<<'\n';
    return 0;

}
