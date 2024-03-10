```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long double


int cut(int n){
    if(n <= 1) return 1;
    return 1 + cut(n/2);
}


signed main(){
    int n;
    cin>>n;
    cout<<cut(n)<<'\n';
    return 0;
}
