```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    
    cin>>t;
    while(t--){
        cin>>n;
        cout<<(n/4) + ((n%4)/2)<<'\n';
    }
    return 0;
} 
