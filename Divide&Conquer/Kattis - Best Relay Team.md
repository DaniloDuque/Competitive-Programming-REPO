```cpp
#include <bits/stdc++.h>
using namespace std;


#define double long double
#define get(i, j) (get<i>(run[j]))
#define duo pair<double, vector<string>>
#define f first 
#define s second



string name;
int n;
double a_i, b_i;
vector<tuple<double, double, string>> run;
duo rslt;



duo time(int frstLeg){

    duo rslt = {get(1, frstLeg), {get(2, frstLeg)}}; 
    int j = 0;
    
    for(int i = 0; i<n && j<3; i++) 

        if(i != frstLeg){
            rslt.f += get(0, i); j++;
            rslt.s.push_back(get(2, i));
        }

    return rslt;

}


int main(){

    ios::sync_with_stdio(0); cin.tie(NULL); 
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>name>>a_i>>b_i;
        run.emplace_back(b_i, a_i, name);

    }sort(run.begin(), run.end());

    duo rslt = {100, {}};
    for(int i = 0; i<n; i++) rslt = min(rslt, time(i));
    cout<<setprecision(19)<<rslt.f<<'\n';
    for(auto &s: rslt.s) cout<<s<<'\n';
    return 0;

}
