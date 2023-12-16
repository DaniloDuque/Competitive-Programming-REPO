```cpp
#include <bits/stdc++.h>
using namespace std;

string s;



void accumulatedList(){

    vector<int> accumulatedList; accumulatedList.push_back(0); int maX = 0, miN = 0, x = 0, y = 0;
    for(int i = 0; i<s.length(); ++i){

        accumulatedList.push_back(1 - 2*(s[i] == 'R') + accumulatedList.back());

        if(maX < accumulatedList.back()){

            maX = accumulatedList.back();
            x = i+1;

        }
        if(miN > accumulatedList.back()){

            miN = accumulatedList.back();
            y = i+1;

        }

    }

    int finish = max(x, y);
    int start = min(x, y);
    cout<<((start == 1)? start: start+1)<<" "<<finish<<endl;

}




int main(){

    std::ios::sync_with_stdio(false);
    cin>>s;
    accumulatedList();
    return 0;

}
