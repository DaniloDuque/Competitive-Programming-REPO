```cpp
#include <bits/stdc++.h>
using namespace std;


#define ll long long
int t, n, a, x;
vector<ll> lss, grt, eql; 


int main(){

    ios::sync_with_stdio(0);    
    cin>>t;
    while(t--){

        lss.clear(); grt.clear(); eql.clear();
        cin>>n;
        while(n--){

            cin>>a>>x;
            (a == 1)? grt.push_back(x): (a == 2)? lss.push_back(x) : eql.push_back(x);

        }sort(grt.begin(), grt.end()); sort(lss.begin(), lss.end());

        ll range = max(0LL, lss[0] - grt[grt.size()-1] + 1);
        for(ll i: eql) if(i <= lss[0] && i >= grt[grt.size()-1]) range--;
        cout<<range<<'\n';

    }return 0;

}
