```cpp
#include <bits/stdc++.h>
using namespace std;


#define oo 2000

int t, n, heights[101], dp[101][1002];



int minHeight(int i, int H = 0){

    if(i == n) return (H)? oo: H;

    if(H < 0) return oo;

    if(dp[i][H] != -1) return dp[i][H];

    return dp[i][H] = max(H, min(minHeight(i+1, H+heights[i]), minHeight(i+1, H-heights[i])));

}


void printPath(int i, int H){

    if(i == n || H < 0) return;

    if(minHeight(i+1, H+heights[i]) < minHeight(i+1, H-heights[i])){
        cout<<'U';
        return printPath(i+1, H+heights[i]);

    }cout<<'D';
    return printPath(i+1, H-heights[i]);

}


int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){

        cin>>n;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i<n; i++) cin>>heights[i];
        if(minHeight(0) == oo) cout<<"IMPOSSIBLE";
        else printPath(0, 0);
        cout<<'\n';

    }return 0;

}
