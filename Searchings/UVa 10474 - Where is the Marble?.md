```cpp
#include <bits/stdc++.h>
using namespace std;

int n, q, x, i = 1;
vector<int> nums;


int main(){

    ios::sync_with_stdio(false);
    while(cin>>n>>q && n && q){

        cout<<"CASE# "<<i++<<":\n";
        nums.assign(n, 0);
        for(int i = 0; i<n; i++) cin>>nums[i];

        sort(nums.begin(), nums.end());

        for(int i = 0; i<q; i++){

            cin>>x;
            int marble = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            (nums[marble] == x)? cout<<x<<" found at "<<marble+1<<'\n': cout<<x<<" not found\n";

        }

    }return 0;

}
