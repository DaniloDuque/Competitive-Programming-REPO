```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, cities[100000], asc[100001], des[100001];



int closest(int i){

    if((i > 0 && abs(cities[i]-cities[i+1]) > abs(cities[i]-cities[i-1])) || i == n-1) return i-1;
    return i+1;

}


void makeDPS(){

    asc[0] = des[n-1] = 0;
    for(int i = 1; i<n; i++) asc[i] = (closest(i-1) == i? 1:abs(cities[i-1]-cities[i])) + asc[i-1];
    for(int i = n-2; i>=0; i--) des[i] = (closest(i+1) == i? 1:abs(cities[i+1]-cities[i])) + des[i+1];

}



int main(){

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i = 0; i<n; i++) cin>>cities[i];
        makeDPS();
        cin>>m;

        while(m--){

            cin>>x>>y;
            cout<<((--x > --y)? des[y]-des[x]: asc[y]-asc[x])<<'\n';

        }

    }return 0;
    
}
