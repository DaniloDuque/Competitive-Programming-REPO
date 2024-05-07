```cpp
#include <bits/stdc++.h>
using namespace std;


int uf[1000001], r, c, n, r_1, c_1, r_2, c_2;
vector<vector<char>> Map;



int Find(int i){
    return (uf[i] == i)? i : uf[i] = Find(uf[i]);
}



void Union(int i, int j){        
    int x = Find(i), y = Find(j);
    if(x == y) return;
    uf[y] = x;
}



int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    iota(uf, uf + 1000000, 0);
    cin>>r>>c;  
    Map.assign(r, vector<char>(c, '\0'));
    for(int i = 0; i<r; ++i)           
        for(int j = 0; j<c; ++j){
            cin>>Map[i][j];
            if(i && Map[i-1][j] == Map[i][j]) Union(i*c + j, (i-1)*c + j);
            if(j && Map[i][j-1] == Map[i][j]) Union(i*c + j, i*c + j - 1);
        }
    
    cin>>n;
    while(n--){
    
        cin>>r_1>>c_1>>r_2>>c_2;
        --r_1; --c_1; --r_2; --c_2;
        if(Find(r_1*c + c_1) == Find(r_2*c + c_2)) cout<<((Map[r_1][c_1] == '1'? "Decimal\n" : "Binary\n"));
        else cout<<"neither\n";
    
    }return 0;

}
