```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAX (int)2e5+20
int t, n, arr[MAX], mex[MAX];

int main(){

    scanf("%d", &t);
    while(t--){
        
        scanf("%d", &n); fill(mex, mex+n+1, 0);
        for(int i = 0; i<n;) scanf("%d", &arr[i++]);
        vector<int> rslt; int m = 0;
        for(int i = 0; i<n; ++i){
            rslt.push_back((arr[i] >= 0)? m : m-arr[i]);
            mex[rslt[i]]++;
            while(mex[m]) m++;
        }for(int &i : rslt) printf("%d ", i); puts("");

    }return 0;

}
