```cpp
#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> trains, lis, lds;


void maxTrains(){

    int rslt = 0;
    for(int i = n-1; i>=0; i--){
        for(int j = i+1; j<n; j++)
            (trains[j] > trains[i])? lis[i] = max(lis[i], lis[j]+1): lds[i] = max(lds[i], lds[j]+1);
    
        rslt = max(rslt, lis[i] + lds[i] - 1);   //if we choose the initial car to be i, then the length will be LIS[i] + LDS[i] - 1

    }cout<<rslt<<'\n';

}


int main(){

    ios::sync_with_stdio(0);
    cin>>n;
    trains.assign(n, 0); lis.assign(n, 1); lds.assign(n, 1);
    for(int i = 0; i<n; i++) cin>>trains[i];
    maxTrains();
    return 0;

}
