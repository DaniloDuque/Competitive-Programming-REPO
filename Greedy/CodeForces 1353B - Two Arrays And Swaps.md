```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, k, A[30], B[30];


int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n>>k;
        for(int i = 0; i<n; i++) cin>>A[i];
        for(int i = 0; i<n; i++) cin>>B[i];
        sort(A, A+n); sort(B, B+n, greater<int>());

        int cont = 0, sum = 0;
        for(int i = 0; i<n; i++){

            if(A[i] < B[i] && cont < k){
                swap(A[i], B[i]);
                cont++;
            }sum += A[i];
        
        }cout<<sum<<'\n';


    }return 0;

}
