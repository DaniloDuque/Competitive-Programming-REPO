```cpp
#include <bits/stdc++.h>
using namespace std;


#define Double long double
int x, y, n, l_i, u_i;
Double factor;
vector<tuple<int, int, Double>> shields;


Double time(){

    Double dis = 0.0;
    int currHeight = 0;
    for(auto i: shields){

        dis += get<0>(i) - currHeight;
        currHeight = get<1>(i);
        dis += (currHeight - get<0>(i)) * get<2>(i);

    }return dis + y - currHeight;
    
}


int main(){

    ios::sync_with_stdio(false);
    cin>>x>>y>>n;
    for(int i = 0; i<n; i++){

        cin>>l_i>>u_i>>factor;
        shields.push_back({l_i, u_i, factor});

    }sort(shields.begin(), shields.end());
    cout<<setprecision(11)<<(x/time())<<'\n';
    return 0;

}
