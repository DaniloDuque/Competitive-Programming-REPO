```cpp
#include <bits/stdc++.h>
using namespace std;

int n, d, i, maxValue;


int findEndValue(int balls, int i = 1){

    int lft = i<<1, rght = lft + 1;
    if(lft >= maxValue || rght >= maxValue) return i;
    if(balls&1) return findEndValue((balls>>1) + 1, lft);
    return findEndValue(balls>>1, rght);

}


int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    
    while(n--){

        cin>>d>>i;
        maxValue = 1<<d;
        cout<<findEndValue(i)<<'\n';

    }return 0;

}
