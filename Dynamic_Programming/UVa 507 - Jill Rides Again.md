```cpp
#include <bits/stdc++.h>
using namespace std;



int b, s, x, maxSum;
vector<int> stops;
pair<int, int> rslt;



void maxBike() {

    pair<int, int> curr;
    int sum = 0; maxSum = INT_MIN;

    for(int i = 0; i < stops.size(); i++) {

        sum += stops[i];

        if(maxSum < sum || (maxSum == sum && (i-curr.first > rslt.second - rslt.first))) {
            maxSum = sum;
            rslt = {curr.first, i};
        }

        if(sum < 0) {
            sum = 0;
            curr.first = i + 1;
        }

    }

}



int main(){

    ios::sync_with_stdio(false);
    cin>>b;
    for(int i = 1; i<=b; i++){

        cin>>s; stops.clear();
        while(--s){
            cin>>x;
            stops.push_back(x);
        }
        maxBike();
        if(maxSum > 0) cout<<"The nicest part of route "<<i<<" is between stops "<<rslt.first+1<<" and "<<rslt.second+2<<'\n';
        else cout<<"Route "<<i<<" has no nice parts\n";


    }return 0;


}
