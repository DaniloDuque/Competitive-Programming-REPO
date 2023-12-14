```cpp
//Kattis cantor

#include <bits/stdc++.h>
using namespace std;







//O(1) ^ o(nlog(n))
double ternaryExpansion(double n, double res, int i = 1){

    if(i > 30) return true;

    double x = 3*n, y = x - floor(x); int mod = static_cast<int>(floor(x))%3;

    if(mod == 1) return false;

    return ternaryExpansion(y, res + mod*pow(10, -i), i+1);

}



//O(n)
int main(){

    double n;
    while(true){

        cin>>n;

        if(cin.fail() || cin.eof()) return 0;

        cout<<((ternaryExpansion(n, (n < 1)? 0: 1))? "MEMBER": "NON-MEMBER")<<endl;

    }

}

