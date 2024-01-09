```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, c = 0;
vector<int> nums;


void swap(int &i, int &j){

    i ^= j;
    j ^= i;
    i ^= j;
    c++;
}


void evenArray(){

    c = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(!(i&1) && nums[i]&1 && j&1 && !(nums[j]&1)) swap(nums[i], nums[j]);

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(!(i&1) && nums[i]&1 || i&1 && !(nums[i]&1)) c=-1;

    cout<<c<<'\n';

}


int main(){

    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){

        cin>>n;
        nums.assign(n, 0);
        for(int i = 0; i<n; i++) cin>>nums[i];
        evenArray();

    }return 0;

}
