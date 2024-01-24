```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
char curr;
bitset<26> solved;

int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n; solved.reset();
        int balloons = 0;
        for(int i = 0; i<n; i++){

            cin>>curr;
            balloons += 2 - (solved.test(curr-'A'));
            solved.set(curr-'A'); 

        }cout<<balloons<<'\n';


    }return 0;

}
