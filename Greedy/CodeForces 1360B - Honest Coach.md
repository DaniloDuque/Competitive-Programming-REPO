```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, ath[50];

int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 0; i<n; i++) cin>>ath[i];

        sort(ath, ath+n);

        int minDiff = INT_MAX;
        for(int i = 1; i<n; i++) minDiff = min(minDiff, abs(ath[i]-ath[i-1]));
        cout<<minDiff<<'\n';


    }return 0;

}
