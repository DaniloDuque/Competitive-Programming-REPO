```cpp
#include <bits/stdc++.h>
using namespace std;


bitset<201> nums;
int n, x, l;


int main(){

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>x;
        nums.set(x);
        l = x;

    }if(nums.count() == l) cout<<"good job\n";
    else for(int i = 1; i<l; i++) if(!nums.test(i)) cout<<i<<'\n';
    return 0;

}
