```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pi pair<int, int> 

int v, prices[9];
pi arr[9]; 
string s = "";

bool f(pi x, pi y){
    if(x.first == y.first) return x.second > y.second;
    return x.first < y.first;
}

bool cmp(pi x, pi y){
    return x.second > y.second;
}


signed main(){

    cin>>v;
    for(int i = 0; i<9; ++i){
        cin>>prices[i]; 
        arr[i] = make_pair(prices[i], i);
    } 

    sort(arr, arr+9, f);
    if(arr[0].first > v){
        puts("-1");
        return 0;
    } 

    while(v >= arr[0].first){
        s += to_string(arr[0].second);
        v -= arr[0].first;
    }
    
    sort(arr, arr+9, cmp);
    for(int i = 0; i<s.size(); ++i)
        for(int j = 0; j<9; ++j)
            if(v > 0 && s[i] - '0' < arr[j].second && prices[s[i] - '0'] + v >= arr[j].first){
                v -= abs(arr[j].first - prices[s[i] - '0']);
                s[i] = arr[j].second + '0';
            }
    
    for(char c : s) cout<<(int)c - '0' + 1;
    puts("");
    return 0;
}
