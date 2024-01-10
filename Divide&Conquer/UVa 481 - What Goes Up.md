```cpp
#include <bits/stdc++.h>
using namespace std;

int n, End = 0, cont = 0;
vector<int> nums, LIS, idx, path;


void printLIS(int End){

    if(End == -1) return;
    printLIS(path[End]);
    cout<<nums[End]<<'\n';

}

void findLIS(){
    
    for(int i = 0; i<nums.size(); i++){

        int index = lower_bound(LIS.begin(), LIS.begin() + cont, nums[i]) - LIS.begin();

        LIS[index] = nums[i];
        idx[index] = i;
        path[i] = (index)? idx[index-1] : -1;

        if(index == cont){
            ++cont;
            End = i;
        }

    }cout<<cont<<"\n-\n";


}


int main(){

    ios::sync_with_stdio(false);
    while(cin>>n) nums.push_back(n);

    LIS.assign(nums.size(), 0);
    idx.assign(nums.size(), 0);
    path.assign(nums.size(), 0);

    findLIS();
    printLIS(End);
    return 0;

}   
