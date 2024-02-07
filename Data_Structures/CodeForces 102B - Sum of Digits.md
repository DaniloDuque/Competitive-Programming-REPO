```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long
string s;
int sum = 0;


int sums(int i){

    if(!(i/10)) return 0;
    sum = 0;
    while(i){
        sum += i%10;
        i/=10;

    }return 1 + sums(sum);

}

signed main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>s;

    for(int i = 0; s[i]; i++) sum += s[i]-48;
    cout<<sums(sum) + (s.length()>1)<<'\n';
    return 0;

}
