```cpp
#include <bits/stdc++.h>
using namespace std;


#define int long long
int n, m;


bool isPowerOfM(int n){

    int curr = m;
    while(curr < n) curr *= m;
    return curr == n;

}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(cin>>n>>m){

        if((m <= 1) || !isPowerOfM(n)) cout<<"Boring!\n";
        else{
            while(n/m){
                cout<<n<<' ';
                n/=m;
            }cout<<n<<'\n';
        }

    }return 0;

}
