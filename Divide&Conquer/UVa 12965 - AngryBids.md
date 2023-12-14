```cpp
//UVa 12965

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

set<int> prices;







//O(log(j)
int upperBound(vi &arr, int n, int i, int j){

    if(i > j) return i;

    int m = i + (j - i)/2;

    if(arr[m] > n) return upperBound(arr, n, i, m-1);

    return upperBound(arr, n, m+1, j);


}


//O(log(j)
int lowerBound(vi &arr, int n, int i, int j) {

    while (i <= j) {
        int m = i + (j - i) / 2;
        (arr[m] < n) ? i = m + 1 : j = m-1;

    }return i;

}






//O(log(C!*P!))
void findBest(vi &prods, vi &cons, int P, int C){

    sort(prods.begin(), prods.end());  //O(log(|prods|!))
    sort(cons.begin(), cons.end());    //O(log(|cons|!))
    int minPrice, minAngry = INT_MAX;

    for(auto i: prices){

        int consAngry = lowerBound(cons, i, 0, C-1);        //O(log(|cons|))
        int prodAngry = P - upperBound(prods, i, 0, P-1);   //O(log(|prods|))

        if(consAngry + prodAngry < minAngry){

            minPrice = i;
            minAngry = consAngry + prodAngry;

        }

    }cout<<minPrice<<" "<<minAngry<<'\n';


}









//O(nlog(C!*P!))
int main(){

    std::ios::sync_with_stdio(false);
    int n, P, C, x;
    cin>>n;
    for(int i = 0; i<n; ++i){

        cin>>P>>C;
        prices.clear(); vi prods, cons; prices.insert(0);  //this covers the case, P equals 0
        for(int j = 0; j<P; j++){
            cin>>x; prods.push_back(x); prices.insert(x);
        }
        for(int j = 0; j<C; j++){
            cin>>x; cons.push_back(x); prices.insert(x);
        }
        findBest(prods, cons, P, C);

    }return 0;


}
