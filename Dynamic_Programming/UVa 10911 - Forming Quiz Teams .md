```cpp
#include <bits/stdc++.h>
using namespace std;




#define SET(s, i) ((s)|(1<<(i)))
#define TEST(s, i) ((s)&(1<<(i)))



int n, Case = 0, arr[2][16], endState;
char name[20];
double dp[1<<16];




double distance(int x_1, int y_1, int x_2, int y_2){
    return sqrt((x_1-x_2)*(x_1-x_2) + (y_1-y_2)*(y_1-y_2));
}


double minSum(int state){

    if(state == endState) return 0;

    double &mem = dp[state];
    if(mem != -1) return mem;
    mem = 1e9;

    for(int i = 0; i<(n<<1); ++i)
        for(int j = i+1; j<(n<<1); ++j)
            if(!TEST(state, i) && !TEST(state, j)) 
                mem = min(mem, distance(arr[0][i], arr[1][i], arr[0][j], arr[1][j]) + minSum(SET(state, i)|SET(state, j)));

    return mem;

}




int main(){

    while(scanf("%d", &n) && n){
 
        endState = (1<<(n<<1))-1;
        for(int i = 0; i<=endState; ++i) dp[i] = -1;
        for(int i = 0; i<(n<<1); ++i) scanf("%s %d %d", name, &arr[0][i], &arr[1][i]);
        printf("Case %d: %.2f\n", ++Case, minSum(0));
        
    }return 0;

}
