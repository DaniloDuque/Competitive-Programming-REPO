```cpp
#include <bits/stdc++.h>
using namespace std;

int n, arr[100000], lis[100000], idx[100000], path[100000];


void printLIS(int end){

    if(end == -1) return;
    printLIS(path[end]);
    cout<<end<<" ";

}


void LIS(){

    int end = 0, c = 0;
    for(int i = 0; i<n; i++){

        int index = lower_bound(lis, lis+c, arr[i]) - lis;
        lis[index] = arr[i];
        idx[index] = i;
        path[i] = (index)? idx[index-1]: -1;

        if(index == c){
            c++;
            end = i;
        }

    }cout<<c<<'\n';
    printLIS(end);

}


int main() {

    ios::sync_with_stdio(0);
    while(cin>>n){

        for(int i = 0; i<n; i++) cin>>arr[i];
        fill(lis, lis + n, 0);
        fill(idx, idx + n, 0);
        fill(path, path+n, 0);
        LIS();
        cout<<'\n';

    }return 0;

}
