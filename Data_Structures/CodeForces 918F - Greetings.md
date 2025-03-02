```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;


#define redBlack __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>

int n, s, a, b;
vector<pair<int, int>> greets;



void getGreetings(){

    long long greetings = 0;
    redBlack tree;

    for(pair<int, int>& duo : greets){

        greetings += tree.size() - tree.order_of_key(duo.second);
        tree.insert(duo.second);
    
    }cout<<greetings<<'\n';

}


int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){

        cin>>s; greets.clear();
        while(s--){

            cin>>a>>b;
            greets.push_back({b, a});

        }sort(greets.begin(), greets.end());  //sorts the greets vector, considering only the first value of each pair.
        getGreetings();

    }return 0;

}
