```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 2e5 + 20;
int t, n, nums[MAX];
string chs;

int accSum(int i, int j){return nums[j] - nums[i-1];}

signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 1; i<=n; ++i) cin>>nums[i], nums[i] += nums[i-1];
        cin>>chs;
        int i = 1, j = n, points = 0;
        while(i < j){
            if(chs[i-1] == 'L' && chs[j-1] == 'R') points += accSum(i++, j--); 
            else if(chs[i-1] == 'L') j--;
            else if(chs[j-1] == 'R') i++;
            else --j, ++i;
        }cout<<points<<'\n';

    }return 0;

}
