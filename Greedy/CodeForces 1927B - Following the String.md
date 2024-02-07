```cpp
#include <bits/stdc++.h>
using namespace std;


int t, n, arr[200001], ch[26];


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>t;
    while(t--){

        cin>>n; fill(ch, ch+26, 0);
        for(int i = 0; i<n; i++) cin>>arr[i];

        for(int i = 0; i<n; i++){

            int j = 0;
            while(ch[j] != arr[i]) j++;
            ch[j]++;
            cout<<char(j+'a');

        }cout<<'\n';


    }return 0;

}
