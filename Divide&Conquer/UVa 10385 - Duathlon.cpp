//UVa 10385

#include <bits/stdc++.h>
using namespace std;


#define comp pair<double, double>
#define epsilon 1e-8





//O(1)
double getTime(double x, double r, double c, int t){
    return (x/r + (t-x)/c);
}

//x + y = t -> y = t-x




//O(|comps|)
double closestCompetitor(vector<comp> &comps, double x, int t){

    double lowestTime = DBL_MAX;
    double cheaterTime = getTime(x, comps.back().first, comps.back().second, t);
    for(int i = 0; i<comps.size()-1; i++) lowestTime = min(lowestTime, getTime(x, comps[i].first, comps[i].second, t));
    return (cheaterTime - lowestTime)*3600.0;

}





//|comps|log(t/epsilon)
double ternarySearch(vector<comp> &comps, double left, double right, int t){

    if(fabs(right-left) <= epsilon) return left;

    double m1 = (right+right+left)/3, m2 = (right+left+left)/3;
 
    if(closestCompetitor(comps, m1, t) > closestCompetitor(comps, m2, t)) return ternarySearch(comps, left, m1, t);
    
    return ternarySearch(comps, m2, right, t);

}





//O(|comps|log(t))
void calculateTime(vector<comp> &comps, int t){

    double x = ternarySearch(comps, 0, t, t);  //Calculate optimum running distance
    
    if (closestCompetitor(comps, x, t) > 0){   //if the minimum difference in time between cheater and all competitors is greater than 0, then some competitor wins before the cheater, with r = x
        
        cout << "The cheater cannot win.\n"; return;


    }cout << "The cheater can win by " << (int)round(-closestCompetitor(comps, x, t)) << " seconds with r = " << fixed << setprecision(2) << x << "km and k = " << t - x << "km.\n"; 
    //else, the ahead time of the cheater equals, lowestTimeOfCompetitor - cheaterTime<
    
}




int main(){

    vector<comp> competitors;
    int n, t;
    while(cin>>t>>n){

        competitors.assign(n, {});
        for(int i = 0; i<n; i++){

            cin>>competitors[i].first>>competitors[i].second;

        }calculateTime(competitors, t);

    }return 0;

}
