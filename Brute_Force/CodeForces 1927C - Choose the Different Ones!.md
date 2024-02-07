```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, x;
unordered_set<int> sN, sM;


void solve(){

    int countN = 0, countM = 0;
    for(int i = 1; i<=k; ++i){

        if(!sN.count(i)) countM++;
        if(!sM.count(i)) countN++;
        if(countM > (k>>1) || countN > (k>>1) || (!sN.count(i) && !sM.count(i))){
            cout<<"NO\n"; return;
        }

    }cout<<"YES\n";
}


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n>>m>>k;
        for(int i = 0; i<n; i++){
            cin>>x;
            sN.insert(x);
        }
        for(int i = 0; i<m; i++){
            cin>>x;
            sM.insert(x);

        }solve();
        sN.clear(); sM.clear();


    }return 0;

}
