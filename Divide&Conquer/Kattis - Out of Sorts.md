```cpp
#include <bits/stdc++.h>
using namespace std;


#define ll long long

ll n, m, a, c, x0;
vector<ll> seq;


int binarySearch(int x){

    int i = 0, j = seq.size()-1;
    while(i < j){

        int m = (i+j)>>1;

        if(seq[m] == x) return m;

        (x > seq[m])? i = m+1: j = m-1;

    }return i;

}


int main(){

    ios::sync_with_stdio(false);
    cin>>n>>m>>a>>c>>x0; int count = 0;
    seq.push_back((a*x0 + c) % m);

    for(int i = 1; i<n; i++) seq.push_back((a*seq.back() + c) % m);
    for(int i = 0; i<n; i++) count += (seq[i] == seq[binarySearch(seq[i])]);

    cout<<count<<'\n';

    return 0;

}
