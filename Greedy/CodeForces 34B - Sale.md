```cpp
#include <bits/stdc++.h>
using namespace std;

int n, k, sum = 0;


int main(){

    ios::sync_with_stdio(0);
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i<n;i++) cin>>arr[i];
    sort(arr, arr+n);

    for(int i = 0; i<k && arr[i] < 0; i++) sum += -arr[i];

    cout<<sum<<'\n';
    return 0;

}
