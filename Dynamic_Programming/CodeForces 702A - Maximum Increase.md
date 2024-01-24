```cpp
#include <bits/stdc++.h>
using namespace std;

int n, nums[100000];


int main(){

    ios::sync_with_stdio(0);
    cin>>n>>nums[0];
    int max_length = 1, current_length = 1;

    for(int i = 1; i < n; i++){
        
        cin>>nums[i];
        if (nums[i] > nums[i - 1]) current_length++;

        else{
            max_length = max(max_length, current_length);
            current_length = 1;
        }
    
    }cout<<max(max_length, current_length)<<'\n';
    return 0;

}
