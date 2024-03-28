```cpp
#include <bits/stdc++.h>
using namespace std;

char board[8], c;


bool valid(){

    for(int i = 0; i<8; ++i){
        if(board[i] == -1) return 0;
        for(int j = i+1; j<8; ++j)
            if(abs(j-i) == abs(board[j] - board[i]) || board[i] == board[j]) return 0;

    }return 1;

}


int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    memset(board, -1, sizeof(board));

    for(int i = 0; i<8; ++i)
        for(int j = 0; j<8; ++j){
            cin>>c;
            if(c == 42) board[j] = i;
        }

    cout<<(valid()? "valid": "invalid")<<'\n';
    return 0;

}
