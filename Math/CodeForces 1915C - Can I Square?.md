```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long unsigned
int t, n;
ll s, sum;


ll root(ll n, ll i, ll j){

    ll m = (i+j)>>1;
    if(m*m > n) return root(n, i, m-1);
    if((m+1)*(m+1) > n) return m;
    return root(n, m+1, j);

}

int main(){

    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){

        cin>>n; sum = 0;
        while(n--){

            cin>>s;
            sum+=s;

        }ll r = root(sum, 0, sum);
        cout<<((r*r == sum)? "YES\n": "NO\n");

    }return 0;

}
