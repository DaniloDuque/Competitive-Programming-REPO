```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

void correct(){
    stack<int> st;
    for(int i = 0; i<n; ++i) 
        if(s[i] == '(') st.push(1);
        else if(st.empty() && !(i&1)) s[i] = '(';
        else if(!st.empty()) st.pop();
}

int cost(){
    stack<int> st; int cost = 0;
    for(int i = 0; s[i]; ++i)
        if(s[i] == '(') st.push(i);
        else{
            cost += i - st.top(); st.pop();
        } 
    return cost; 
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        
        cin>>n>>s; s[0] = '(';
        for(int i = 2; s[i]; ++i, ++i) s[i] = ')'; 
        correct();
        cout<<cost()<<'\n';

    }return 0;

}
