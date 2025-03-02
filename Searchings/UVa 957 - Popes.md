```cpp
#include <bits/stdc++.h>
using namespace std;

int y, n, arr[100001];


int main() {

    ios::sync_with_stdio(0);
    while(cin>>y>>n){

        for(int i = 0; i<n; i++) cin>>arr[i];

        int max = 0, frst = arr[0], lst = arr[0];

        for(int i = 0; i<n; i++){

            int index = upper_bound(arr+i, arr+n, arr[i]+y-1)-arr-1;
            if(max < index-i+1){
                
                max = index-i+1;
                frst = arr[i];
                lst = arr[index];

            }

        }cout<<max<<" "<<frst<<" "<<lst<<'\n';

    }return 0;

}
