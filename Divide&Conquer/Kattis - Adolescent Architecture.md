```cpp
#include <bits/stdc++.h>
using namespace std;


#define duo pair<int, bool>
int n, a;
duo arr[100];
string s;


bool cmp(duo &a, duo &b){

    double area1 = a.first * a.first * (a.second? M_PI: 1);
    double area2 = b.first * b.first * (b.second? M_PI: 1);
    return (area1 > area2)? 1: 0;

}


bool possible(){

    for(int i = 1; i<n; ++i){

        if((arr[i].second && !arr[i-1].second) && (2 * arr[i].first > arr[i-1].first)) return 0;
        if((!arr[i].second && arr[i-1].second) && (arr[i].first * arr[i].first > arr[i-1].first * arr[i-1].first * 2)) return 0; 
        if(arr[i].second == arr[i-1].second && arr[i].first > arr[i-1].first) return 0;

    }return 1;

}



int main(){

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0; i<n; ++i){
        cin>>s>>a;
        arr[i] = {a, (s == "cube")? 0: 1};

    }sort(arr, arr+n, cmp);
    if(!possible()) cout<<"impossible\n";
    else for(int i = n-1; i>=0; --i) cout<<(arr[i].second? "cylinder ": "cube ")<<arr[i].first<<'\n';
    return 0;

}
