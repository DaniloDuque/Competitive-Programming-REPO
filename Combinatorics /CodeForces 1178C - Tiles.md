```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int p = 998244353; 
int w, h;

int Poww(int b, int e){
    if(!e) return 1;
    if(e&1) return (Poww((b*b)%p, e>>1)*b)%p;
    return Poww((b*b)%p, e>>1)%p;
}

signed main(){
    scanf("%lld %lld", &w, &h);
    printf("%lld\n", Poww(2, w+h));
    return 0;
}
