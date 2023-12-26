```cpp
#include <bits/stdc++.h>
using namespace std;


int n, k;
vector<int> bets;



int maxStreak(){

    int i = 0, sum = 0, maxSum = INT_MIN;
    for(int i = 0; i<bets.size(); i++){

        sum += bets[i];
        maxSum = max(maxSum, sum);
        sum = max(sum, 0);

    }return maxSum;

}



int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    while(n){

        bets.assign(n, 0);
        for(int i = 0; i<n; i++) cin>>bets[i];

        int streak = maxStreak();
        (streak < 1)? cout<<"Losing streak.\n" : cout<<"The maximum winning streak is "<<streak<<".\n";
        cin>>n;

    }return 0;


}
