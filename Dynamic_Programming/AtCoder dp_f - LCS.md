```cpp
#include <bits/stdc++.h>
using namespace std;

int dp[3002][3002];

string a, b, res;



string LCS(){

    int lenA = a.length(), lenB = b.length();

    for(int i = lenA-1; i>=0; i--)
        for(int j = lenB-1; j>=0; j--){

            dp[i][j] = (a[i] == b[j])? dp[i][j] = 1 + dp[i+1][j+1]: max(dp[i+1][j], dp[i][j+1]);

        }

    int i = 0, j = 0;
    while(i < lenA && j < lenB){

        if(a[i] == b[j]){

            res += a[i++]; j++;

        }else if(dp[i+1][j] > dp[i][j+1]) i++;
        else j++;

    }return res;


}




int main(){

    cin>>a>>b;
    cout<<LCS()<<'\n';
    return 0;

}
