#include <bits/stdc++.h>
using namespace std;


#define oo 100000
int roads[100][100], dp[100][100];
int n, m, st, fn, v1, v2, l, rslt = 0;



int main(){

    cin>>n>>m>>st>>fn; --st; --fn;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            dp[i][j] = oo*(i!=j);

    while(m--){

        scanf("%d %d %d", &v1, &v2, &l);
        roads[--v1][--v2] = l;
        dp[v1][v2] = dp[v2][v1] = l;

    }

    for(int i = 0; i<n; i++)    
        for(int j = 0; j<n; j++)
            for(int k = 0; k<n; k++)
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);

    for(int i = 0; i<n; i++)    
        for(int j = 0; j<n; j++)
            if(roads[i][j] && (dp[st][i] + roads[i][j] + dp[j][fn] != dp[st][fn]) && (dp[st][j] + roads[i][j] + dp[i][fn] != dp[st][fn]))
                rslt += roads[i][j];
    
    printf("%d\n", rslt);
    return 0;

}