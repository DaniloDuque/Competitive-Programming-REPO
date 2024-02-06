```cpp
#include <bits/stdc++.h>
using namespace std;

int n;
string arr[20], decr[20], inc[20];


int main() {

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        decr[i] = inc[i] = arr[i];
    }

    sort(inc, inc+n); sort(decr, decr+n, greater<string>());

    bool decreasing = true, increasing = true;
    for(int i = 0; i<n; i++){

        if(arr[i] != decr[i]) decreasing = false;
        if(arr[i] != inc[i]) increasing = false;

    }cout<<((increasing)? "INCREASING\n": (decreasing)? "DECREASING\n": "NEITHER\n");

    return 0;

}
