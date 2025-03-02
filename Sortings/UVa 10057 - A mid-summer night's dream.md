```cpp
//UVa 10057

#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>


//O(|arr|log(|arr|))
void findBests(vi &arr){

    int contEqual = 0;
    sort(arr.begin(), arr.end()); //O(|arr|log(|arr|))

    int x = arr[(arr.size()-1)>>1];
    int y = arr[arr.size()>>1];

    for(int i: arr) contEqual += (x == i || i == y); //O(|arr|)

    cout<<x<<" "<<contEqual<<" "<<y-x+1<<'\n';

}




int main(){

    std::ios::sync_with_stdio(false);
    int n, x;
    while(cin>>n){

        vi nums;
        for(int i = 0; i<n; ++i){

            cin>>x;
            nums.push_back(x);

        }findBests(nums);

    }return 0;

}
