```cpp
#include <bits/stdc++.h>
using namespace std;
    
#define vi vector<long long> 
    
int t, n, s_i;
vector<vi> uni;
vi studs;
    
    
    
void solve(){
    
    for(vi &row: uni)
        for(int i = row.size()-2; i>=0; i--)
            row[i] += row[i+1];

    vi ans(n);

    for(vi &row: uni)
        for(int i = 1; i<=row.size(); i++)
            ans[i-1] += row[0] - row[i*((row.size()-1)/i)];

    for(auto &i: ans) cout<<i<<' '; cout<<'\n';
    
}
    
    
int main(){
    
    ios::sync_with_stdio(0); cin.tie(NULL); 
    cin>>t;
    while(t--){
    
        cin>>n; uni.assign(n, {0});
        studs.assign(n, 0);
        for(int i = 0; i<n; i++) cin>>studs[i];
    
        for(int i = 0; i<n; i++){
            cin>>s_i;
            uni[studs[i]-1].push_back(s_i);
    
        }for(int i = 0; i<n; i++) sort(uni[i].begin(), uni[i].end(), greater<int>());
    
        solve();
    
    }return 0;
    
}
