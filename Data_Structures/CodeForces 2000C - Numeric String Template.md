```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
int t, n, m, arr[MAX]; 
string s;
map<char, int> lets;
map<int, char> nums;

bool match(){

    lets.clear(); nums.clear();
    if(s.size() != n) return 0;    
    for(int i = 0; i<n; ++i){ 
        if(lets.count(s[i]) && arr[i] != lets[s[i]]) return 0;
        if(nums.count(arr[i]) && s[i] != nums[arr[i]]) return 0;
        lets[s[i]] = arr[i]; nums[arr[i]] = s[i];
    }return 1;

}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
    
        cin>>n;
        for(int i = 0; i<n;) cin>>arr[i++];
        cin>>m;
        for(int i = 0; i<m; ++i){
            cin>>s;
            cout<<(match()? "YES" :"NO")<<'\n';
        }


    }return 0;

}
