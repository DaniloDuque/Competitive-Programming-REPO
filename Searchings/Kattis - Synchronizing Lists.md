```cpp
#include <bits/stdc++.h>
using namespace std;

bool first = true;
int n;
vector<int> arr1, arr2, arr3;


int main(){

    ios::sync_with_stdio(false);
    while(cin>>n && n){

        if(!first) cout<<'\n';

        arr1.assign(n, 0); arr2.assign(n, 0); arr3.assign(n, 0);
        for(int i = 0; i<n; ++i){cin>>arr1[i]; arr2[i] = arr1[i];}
        for(int i = 0; i<n; i++) cin>>arr3[i];

        sort(arr2.begin(), arr2.end());
        sort(arr3.begin(), arr3.end());

        for(int i: arr1) cout<<arr3[lower_bound(arr2.begin(), arr2.end(), i) - arr2.begin()]<<'\n';

        first = false;

    }return 0;

}
