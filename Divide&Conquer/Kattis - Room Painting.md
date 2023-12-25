```cpp
#include <bits/stdc++.h>
using namespace std;

int n, k, x;
vector<int> cans;


int main(){

    ios::sync_with_stdio(false);
    cin>>n>>k; 
    while(n--){

        cin>>x;
        cans.push_back(x);

    }sort(cans.begin(), cans.end());
    long long rslt = 0;
    while(k--){

        cin>>x;
        int low = lower_bound(cans.begin(), cans.end(), x) - cans.begin();
        rslt += min(abs(cans[low] - x), abs(cans[low+1] - x));

    }cout<<rslt<<'\n';
    return 0;

}
