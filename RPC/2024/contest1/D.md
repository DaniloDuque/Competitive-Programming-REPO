```cpp
#include <bits/stdc++.h>
using namespace std;



#define duo pair<int, char>
string s;
int q, A[50002], T[50002], G[50002], C[50002], i, b;
duo rslt[4];




int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin>>s>>q;
    
    for(int i = 0; s[i]; i++){

        A[i+1] = A[i]; T[i+1] = T[i];
        G[i+1] = G[i]; C[i+1] = C[i];
        (s[i] == 'T')? T[i+1]++: (s[i] == 'A')? A[i+1]++: (s[i] == 'G')? G[i+1]++: C[i+1]++;

    }while(q--){

        cin>>i>>b;
        rslt[0] = {A[b] - A[i-1], 'A'};
        rslt[1] = {T[b] - T[i-1], 'T'};
        rslt[2] = {G[b] - G[i-1], 'G'};
        rslt[3] = {C[b] - C[i-1], 'C'};
        sort(rslt, rslt + 4, [](duo& a, duo& b) {return a.first > b.first;});        
        for(int i = 0; i<4; i++) cout<<rslt[i].second;
        cout<<'\n';

    }return 0;

}
