```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m, k;


int mcd(int a, int b){

    if(!b) return a;
    return mcd(b, a%b);

}

int mcm(int a, int b){
    return (a*b)/mcd(a, b);
}


int main(){

    cin>>n>>m>>k;
    cout<<((mcm(n, m) <= k)? "yes\n": "no\n");
    return 0;

}
