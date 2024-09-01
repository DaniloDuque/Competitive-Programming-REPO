```cpp
#include <bits/stdc++.h>
using namespace std;

int t, a, b, arr[30];

bool possible(int i, int sum=0){
    if(i == a+b) return !sum;
    return possible(i+1, sum+arr[i]) || possible(i+1, sum-arr[i]);
}

int main(){
    cin>>t;
    while(t--){
        memset(arr, 0, sizeof(arr));
        cin>>a>>b;
        for(int i = 0; i<a; ++i) arr[i]=1;
        for(int i = a; i<b; ++i) arr[i]=2;
        cout<<(possible(0)? "YES" : "NO")<<'\n';
    }return 0;
}
