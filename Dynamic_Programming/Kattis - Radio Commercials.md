```cpp
#include <bits/stdc++.h>
using namespace std;


int n, p, x;
vector<int> studs;



int maxProfit(){

    int i = 0, sum = 0, maxSum = INT_MIN;
    while(i < n){

        sum += studs[i];
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);
        i++;

    }return maxSum;

}



int main(){

    ios::sync_with_stdio(false);
    cin>>n>>p;
    for(int i = 0; i<n; i++){
        
        cin>>x;
        studs.push_back(x-p);
    }
    cout<<maxProfit()<<'\n';
    return 0;

}
