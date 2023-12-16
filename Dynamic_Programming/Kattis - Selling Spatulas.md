```cpp
#include <bits/stdc++.h>
using namespace std;

int n, t; 
long double p, COST = 0.08;
vector<int> times;
vector<long double> profits;




void accumulatedList(){


    vector<long double> accumulatedList; accumulatedList.push_back(0.0);
    for(int i = 0; i<n; i++) accumulatedList.push_back(accumulatedList.back() + profits[i]);

    long double max = 0.0;
    int x, y;


    for(int i = 1; i<=n; i++){

        for(int j = 1; j<=i; j++){

            long double curr = accumulatedList[i] - accumulatedList[j-1] - (times[i-1] - times[j-1] + 1)*COST;
            if(max < curr){

                max = curr;
                x = times[i-1]; 
                y = times[j-1];

            }else if(max == curr && (((times[i-1] - times[j-1]) < (x - y)) || (((times[i-1] - times[j-1]) == (x - y)) && (y > times[j-1])))){

                x = times[i-1];
                y = times[j-1];
                

            }
            
        }

    }printf((!max)? "no profit\n": "%.2Lf %d %d\n", max, y, x);


}

















int main(){

    std::ios::sync_with_stdio(false);
    cin>>n;
    while(n){

        times.assign(n, 0); profits.assign(n, 0.0);
        for(int i = 0; i<n; i++){


            cin>>times[i];
            cin>>profits[i];

        }accumulatedList();
        cin>>n;

    }return 0;

}
