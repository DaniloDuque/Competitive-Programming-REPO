```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int t, n, m;
ll A[200000], B[200000];



int main(){

    ios::sync_with_stdio(false);
    cin>>t;

    while(t--){

        cin>>n>>m;
        for(int i = 0; i<n; i++) cin>>A[i];
        for(int i = 0; i<m; i++) cin>>B[i];
        sort(A, A+n); sort(B, B+m);

        ll aux = 0;
        for(int i = 0; i<n; i++) aux += abs(A[i] - B[m-i-1]);
        
        ll sum = aux;
        for(int i = 0; i<n; i++) sum = max(sum, aux -= abs(A[n-i-1] - B[m-n+i]) - abs(B[i] - A[n-i-1]));

        cout<<sum<<'\n';


    }return 0;

}
