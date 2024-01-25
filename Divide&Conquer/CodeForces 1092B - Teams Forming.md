```cpp
#include <bits/stdc++.h>
using namespace std;


int n, arr[100];


int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    int sum = 0;
    for(int i = 0; i<n; i+=2) sum += arr[i+1] - arr[i];
    cout<<sum<<'\n';
    return 0;

}
