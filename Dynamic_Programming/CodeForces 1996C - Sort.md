```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, q, l, r, acca[27][(int)2e5 + 20], accb[27][(int)2e5 + 20];
string a, b;

int sum(int l, int r){

    int rslt = 0;
    for(int i = 0; i<26; ++i)
        rslt += abs((acca[i][r] - acca[i][l-1]) - (accb[i][r] - accb[i][l-1]));
    return rslt>>1;

}


int main(){
    
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin>>t;
    while(t--){
       
        cin>>n>>q>>a>>b;
        for(int i = 0; i<26; ++i) accb[i][0] = acca[i][0] = 0;
        for(int i = 1; i<=n; ++i){
            for(int j = 0; j<26; ++j) {
                acca[j][i] = acca[j][i-1];
                accb[j][i] = accb[j][i-1];
            }
            acca[a[i-1] - 'a'][i]++;
            accb[b[i-1] - 'a'][i]++;
        }

        while(q--){
            cin>>l>>r;
            cout<<sum(l, r)<<'\n'; 
        }

    }return 0;

}
