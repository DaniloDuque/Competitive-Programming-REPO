```cpp
#include <bits/stdc++.h>
using namespace std;

int n, arr[3], rslt = 0;

int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0; i<n; i++){

        cin>>arr[0]>>arr[1]>>arr[2];
        rslt += ((arr[0]+arr[1]+arr[2]) > 1);

    }cout<<rslt<<'\n';
    return 0;

}
