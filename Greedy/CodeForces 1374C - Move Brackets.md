```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
char c;


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n; int sum1 = 0, rslt = 0;
        while(n--){

            cin>>c;
            sum1 += (c=='(')? 1: -1;
            rslt += (sum1 < 0);
            sum1 = max(sum1, 0);

        }cout<<rslt<<'\n';


    }return 0;

}
