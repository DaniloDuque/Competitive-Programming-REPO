```cpp
#include <bits/stdc++.h>
using namespace std;


#define MAX 501
bool playsH(int, int);
int t, w, h, dpH[MAX][MAX], dpV[MAX][MAX];
string s;



bool playsV(int w, int h){

    if(w == 1) return 0;
    int &mem = dpV[w][h];
    if(mem != -1) return mem;
    for(int i = 1; i<=(w>>1) && mem; ++i) mem = playsH(i, h) || playsH(w-i, h);
    return mem = !mem;

}


bool playsH(int w, int h){

    if(h == 1) return 0;
    int &mem = dpH[w][h];
    if(mem != -1) return mem;
    for(int i = 1; i<=(h>>1) && mem; ++i) mem = playsV(w, i) || playsV(w, h-i);
    return mem = !mem;

}



int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    for(int i = 1; i<MAX; ++i)
        for(int j = 1; j<MAX; ++j)
            dpV[i][j] = dpH[i][j] = -1;

    cin>>t;
    while(t--){

        cin>>w>>h>>s;   
        cout<<s<<(((s == "Harry")? playsH(w, h) : playsV(w, h))? " can win" : " cannot win")<<'\n'; 

    }return 0;

}
