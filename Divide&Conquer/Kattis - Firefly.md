```cpp
#include <bits/stdc++.h>
using namespace std;

int n, h, x, y;
vector<int> up, down;

int main(){

    ios::sync_with_stdio(false);
    cin>>n>>h;
    int min = n, c = 0;
    up.assign(h, 0); down.assign(h, 0);
    for(int i = 0; i<(n>>1); i++){
        
        cin>>x>>y;
        up[x-1]++; down[h-y]++;
   
    }for(int i = h-2; i>=0; i--) up[i] += up[i+1];
    for(int i = 1; i<h; i++) down[i] += down[i-1];
    for(int i = 0; i<h; i++) min = std::min(min, up[i] + down[i]);
    for(int i = 0; i<h; i++) c += (up[i] + down[i] == min); 
    cout<<min<<" "<<c<<'\n';
    return 0;

}
