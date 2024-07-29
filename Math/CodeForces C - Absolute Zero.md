```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, arr[(int)2e5 + 20];
vector<int> sol;

bool isPossible(){
    bool odd = 0, even = 0;
    for(int i = 0; i<n; ++i) (arr[i]&1)? odd = 1 : even = 1;
    if(odd & even) return 0;
    for(int i = 29; i>=0; --i){
        sol.push_back(1<<i);
        for(int j = 0; j<n; ++j) arr[j] = abs(arr[j] - (1<<i));
    }
    if(arr[0] == 1) sol.push_back(1);
    return 1;
}

signed main(){
    
    scanf("%d", &t);
    while(t--){

        scanf("%d", &n); sol.clear();
        for(int i = 0; i<n;) scanf("%d", &arr[i++]);

        if(isPossible()){
            printf("%d\n", (int)sol.size());
            for(int i : sol) printf("%d ", i);
        }else printf("-1");
        puts("");
        

    }return 0;

}
