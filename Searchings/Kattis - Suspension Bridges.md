```cpp
#include <bits/stdc++.h>
using namespace std;

#define Double long double
#define eps 0.0000000001
Double d, s;


Double findA(Double d, Double s){

    Double i = 0.0, j = 10e5;
    while(fabs(i-j) > eps){

        Double m = (i+j)/2;
        (m*cosh(d/(2*m)) - m > s)? i = m: j = m;

    }return (i+j)/2;

}


int main() {

    cin>>d>>s;
    Double a = findA(d, s);
    cout<<setprecision(12)<<2*a*sinh(d/(2*a))<<'\n';
    return 0;

}
