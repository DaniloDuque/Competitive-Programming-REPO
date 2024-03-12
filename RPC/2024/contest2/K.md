```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long long
string s;
int arr[3], swaps = 0;


signed main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    for(char& i : s) arr[i-'0']++;
    for(char& i : s) (i == '0')? arr[0]-- : swaps += arr[0];

    for(char& i : s){

        if(i == '1') arr[1]--;
        if(i == '2') swaps += arr[1];

    }cout<<swaps<<'\n';

}
