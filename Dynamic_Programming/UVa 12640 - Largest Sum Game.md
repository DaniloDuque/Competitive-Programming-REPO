```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;


void largestSum(){

    int sum = 0, maxSum = 0;
    for(int i: nums){

        sum += i;
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);

    }cout<<maxSum<<'\n';


}


int main(){

    ios::sync_with_stdio(false);
    string input;
    while(getline(cin, input)){

        istringstream iss(input);
        nums.clear();
        while(iss>>n) nums.push_back(n);
        largestSum();

    }return 0;

}
