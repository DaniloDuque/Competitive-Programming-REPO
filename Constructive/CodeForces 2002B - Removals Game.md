```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 2;
int t, n, a[MAX], b[MAX];

bool bobWins(){
    bool f1 = 1, f2 = 1;
    for(int i = 0; i<n && f1; ++i) f1 &= (a[i] == b[i]); 
    for(int i = 0; i<n && f2; ++i) f2 &= (a[i] == b[n-1-i]);
    return f1 | f2;
}
    
int main(){
    
    scanf("%d", &t);
    while(t--){
    
        scanf("%d", &n);
        for(int i = 0; i<n;) scanf("%d", &a[i++]);
        for(int i = 0; i<n;) scanf("%d", &b[i++]);
        puts(bobWins()? "Bob" : "Alice");

    }return 0;

}
