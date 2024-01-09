```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cards;


void scores(){

    bool turn = true;
    int S = 0, D = 0, i = 0, j = n-1;
    while(i <= j){

        (turn)? S += max(cards[i], cards[j]): D += max(cards[i], cards[j]);
        (cards[i] > cards[j])? i++: j--;
        turn = !turn;

    }cout<<S<<" "<<D<<'\n';

}


int main(){

    cin>>n; cards.assign(n, 0);
    for(int i = 0; i<n; i++) cin>>cards[i];
    scores();
    return 0;

}
