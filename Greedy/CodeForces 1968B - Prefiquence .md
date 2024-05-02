```cpp
#include <bits/stdc++.h>
using namespace std;


#define MAX 200002
int t, n, m;
char s[MAX], w[MAX];



int maxPrefix(){

    int max = 0, j = 0;
    for(int i = 0 ;i<n; ++i){
        for(;j<m; ++j) 
            if(s[i] == w[j]){
                max++; j++;
                break;
            } 

        if(j == m) return max;

    }return max;

}



int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){

        cin>>n>>m; 
        for(int i = 0; i<n; ++i) cin>>s[i];
        for(int i = 0; i<m; ++i) cin>>w[i];
        cout<<maxPrefix()<<'\n';
    
    }return 0;

}
