```cpp
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int s, n, m;
vi arr, indx;



int maximumWeight(int m){

    int globalMax = 0;

    for(int i: indx){

        int maxSum = m;
        int lft = i-1, rght = i+1;
        while(lft >= 0 && arr[lft] > m) maxSum += arr[lft--];
        while(rght < n && arr[rght] > m) maxSum += arr[rght++];
        globalMax = max(globalMax, maxSum);

    }return globalMax;

}






int main(){

    int x;
    cin>>s;
    while(s--){

        cin>>n>>m;
        arr.clear(); indx.clear();
        for(int i = 0; i<n; i++){
            cin>>x;
            arr.push_back(x);
            if(x == m) indx.push_back(i);


        }cout<<maximumWeight(m)<<'\n';
        

    }return 0;

    
}
