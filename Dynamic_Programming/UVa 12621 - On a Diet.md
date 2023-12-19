```cpp
#include <bits/stdc++.h>
using namespace std;

int n, c, k;    
vector<int> courses;
vector<vector<int>> dp;




int minCalories(int i, int cal = 0){
    
    if(i == k || cal >= c) return cal;   // Base case: No more courses available or the total calorie intake exceeds our limit.

    if(dp[i][cal] != -1) return dp[i][cal];

    int choose = minCalories(i+1, cal + courses[i]);   //result from eating in ith course
 
    int notChoose = minCalories(i+1, cal);             //result from not eating in ith course

    if(choose >= c && notChoose >= c) return dp[i][cal] = min(choose, notChoose);

    return dp[i][cal] = max(choose, notChoose);

}






int main(){

    ios::sync_with_stdio(0);
    cin>>n;
    while(n--){

        cin>>c>>k;
        courses.assign(k, 0); dp.assign(k+1, vector<int>(c+1, -1));
        for(int i = 0; i<k; i++) cin>>courses[i];
        int diet = minCalories(0);
        ((diet >= c)? cout<<diet: cout<<"NO SOLUTION");
        cout<<'\n';

    }return 0;


}
