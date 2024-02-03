```cpp
#include <bits/stdc++.h>
using namespace std;


int n, t;
vector<int> portal;


bool DFS(int curr){

    if(curr > t) return false;
    if(curr == t) return true;
    return DFS(curr + portal[curr]);

}

int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>t; portal.assign(n+1, 0);
    for(int i = 1; i<n; i++) cin>>portal[i];
    cout<<((DFS(1))? "YES\n": "NO\n");
    return 0;

}
