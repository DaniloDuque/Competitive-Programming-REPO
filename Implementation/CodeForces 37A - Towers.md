```cpp
#include <bits/stdc++.h>
using namespace std;

int n, arr[1001], x;

int main(){

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x; arr[x]++;
    }

    cout<<*max_element(arr, arr + 1001)<<' '<<1001 - count(arr, arr+1001, 0)<<'\n';
    return 0;

}
