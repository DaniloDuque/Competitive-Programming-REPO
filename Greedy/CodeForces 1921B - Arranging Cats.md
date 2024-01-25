```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
char A[100000], B[100000];



int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 0; i<n; i++) cin>>A[i];
        for(int i = 0; i<n; i++) cin>>B[i];

        int diff = 0, rslt = 0;
        for(int i = 0; i<n; i++) diff += (A[i] == '1') - (B[i] == '1');
        if(diff > 0) for(int i = 0; i<n; i++) rslt += (A[i] == '1' && B[i] == '0');
        else for(int i = 0; i<n; i++) rslt += (A[i] == '0' && B[i] == '1');

        cout<<rslt<<'\n';
        

    }return 0;

}
