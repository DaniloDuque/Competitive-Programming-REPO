```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[100000];  


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n);

        int present = 1, canCome = 0;
        for(int i = 0; i<n; i++){

            if(arr[i] > present + canCome) canCome++;
            else{
                present += canCome + 1;
                canCome = 0;
            }
        
        }cout<<present<<'\n';

    }return 0;

} 
