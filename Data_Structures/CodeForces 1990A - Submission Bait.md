```cpp
#include <bits/stdc++.h>
using namespace std;

int n, arr[51], t;
map<int, int, greater<int>> m;

bool sol(){
    for(auto &p : m) if(p.second&1) return 1;
    return 0;
}

int main(){

    scanf("%d", &t);
    while(t--){
    
        scanf("%d", &n); m.clear();
        for(int i = 0; i<n;) scanf("%d", &arr[i++]);
        for(int i = 0; i<n;) m[arr[i++]]++;
        sort(arr, arr+n, greater<int>());
        puts((sol())? "YES" : "NO");
                
            
    }return 0;

}
