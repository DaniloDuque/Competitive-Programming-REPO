```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> arr;

int main() {

    ios::sync_with_stdio(0);
    cin>>n;
    arr.assign(n, 0);
    for(int i = 0; i<n; i++) cin>>arr[i];
    cout<<abs(arr[0]-arr[1])<<" "<<abs(arr[0]-arr[n-1])<<'\n';
    for(int i = 1; i<n-1; i++) cout<<min(abs(arr[i]-arr[i-1]), abs(arr[i+1]-arr[i]))<<" "<<max(abs(arr[i]-arr[0]), abs(arr[n-1]-arr[i]))<<'\n';
    cout<<abs(arr[n-1]-arr[n-2])<<" "<<abs(arr[n-1]-arr[0])<<'\n';
    return 0;

}
