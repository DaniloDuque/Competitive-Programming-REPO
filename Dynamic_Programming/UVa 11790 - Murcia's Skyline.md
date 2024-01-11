```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> heights, widths, dp;
bool asc;


bool compare(int a, int b){

    if(asc) return a > b;
    return a < b;

}


int findLS(){

    int LS = 0;
    for(int i = n-1; i>=0; i--){

        int max = 0;
        for(int j = i+1; j<n; j++) if(compare(heights[j], heights[i])) max = std::max(max, dp[j]);
        dp[i] += max;
        LS = std::max(dp[i], LS);

    }return LS;


}


int main(){

    ios::sync_with_stdio(false);
    cin>>t;
    for(int Case = 1; Case<=t; Case++){

        cin>>n;
        heights.assign(n, 0); widths.assign(n, 0);
        for(int i = 0; i<n; i++) cin>>heights[i];
        for(int i = 0; i<n; i++) cin>>widths[i];

        dp.assign(widths.begin(), widths.end()); asc = true;
        int inc = findLS();

        dp.assign(widths.begin(), widths.end()); asc = false;
        int des = findLS();

        cout<<"Case "<<Case<<". ";

        (inc >= des)? cout<<"Increasing ("<<inc<<"). Decreasing ("<<des<<").\n" : cout<<"Decreasing ("<<des<<"). Increasing ("<<inc<<").\n";

    }return 0;

}
