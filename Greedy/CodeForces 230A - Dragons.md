```cpp
#include <bits/stdc++.h>
using namespace std;


int s, n;
vector<pair<int, int>> D;



bool Wins(){

    for(int i = 0; i<n; i++)

        if(D[i].first >= s) return false;
        else s += D[i].second;

    return true;

}


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>s>>n; D.assign(n, {});
    for(int i = 0; i<n; i++) cin>>D[i].first>>D[i].second;

    sort(D.begin(), D.end());

    cout<<((Wins())? "YES\n" : "NO\n");
    return 0;

}
