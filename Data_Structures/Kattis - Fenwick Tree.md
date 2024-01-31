```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long
signed n, q, x, y; 
char i;  
vector<int> fen;    


void add(int i, int x){
    while (i <= n) {
        fen[i] += x;
        i += (i & -i);
    }
}


int sumRange(int i) {
    int s = 0;
    while(i > 0) {
        s += fen[i];
        i -= (i & -i);
    }return s;
}


signed main() {

    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>q;
    fen.assign(n+1, 0);

    while(q--){

        cin>>i>>x;
        if(i == '?') cout<<sumRange(x)<<'\n';
        else{
            cin>>y;
            add(x+1, y);
        }

    }return 0;

}
