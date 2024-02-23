```cpp
#include <bits/stdc++.h>
using namespace std;


string st, fn;
int i = 1, arr[10];
unordered_map<string, bool> Set;


int main(){

    cin>>st>>fn;
    while(st != fn){

        i++;
        if(Set[st]){
            cout<<"Does not appear\n";
            return 0;

        }Set[st] = 1;
        fill(arr, arr+10, 0);
        for(char &c: st) arr[c-'0']++;
        st = "";
        for(int i = 0; i<10; i++) if(arr[i]) st += to_string(arr[i]) + to_string(i);

    }(i > 100)? cout<<"I'm bored\n": cout<<i<<'\n';
    return 0;

}
