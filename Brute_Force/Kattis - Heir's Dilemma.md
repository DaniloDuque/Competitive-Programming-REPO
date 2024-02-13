```cpp
#include <bits/stdc++.h>
using namespace std;


int n, m;
bitset<10> digits;


bool differ(int i){

    digits.reset();
    while(i){
        if(!(i%10) || digits.test(i%10)) return false;
        digits.set(i%10);
        i /= 10;
    }return true;

}

bool valid(int n){

    if(!differ(n)) return false;
    for(int i = 1; i<10; i++) if(digits.test(i) && n%i) return false;
    return true;

}


int main() {

    cin>>n>>m;
    int c = 0;
    for(int i = n; i<=m; i++) if(valid(i)) c++;
    cout<<c<<'\n';
    return 0;

}
