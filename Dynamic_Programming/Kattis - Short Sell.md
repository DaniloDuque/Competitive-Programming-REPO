```cpp
#include <bits/stdc++.h>
using namespace std;

int n, k, p;
vector<int> prices;
int memo[100005];


int profit(int lastSale, int curr){

    return (prices[lastSale] - prices[curr])*100 - (curr - lastSale + 1)*k;

}


int shortSell(int i, int j, bool holds = false){

    if(i == n || prices[j] < prices[i]) return 0;  //if there is no more days, or if the price when we sold isnt optimal

    if(memo[j] != -1) return memo[j];

    if(holds) return memo[j] = max(shortSell(i+1, j, true), profit(j, i));  //if we are holding, there are 2 options, retrieve profit or keep waiting

    return memo[j] = max( shortSell(i+1, i, true), shortSell(i+1, i+1, false)); //else, we have 2 options, dont borrow now, or borrow now

}   





int main(){
    
    cin>>n>>k;

    for(int i = 0; i<n; i++){

        memo[i] = -1;
        cin>>p;
        prices.push_back(p);

    }

    cout<<shortSell(0, 0)<<endl;
    
    return 0;

}
