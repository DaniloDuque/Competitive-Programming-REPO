```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> Map;
int n, m;
bool k;



long long rangeSum(int i, int j, int x, int y){

    if(!i && !j) return Map[x][y];
    if(!i) return Map[x][y] - Map[x][j-1];
    if(!j) return Map[x][y] - Map[i-1][y];
    return Map[x][y] - Map[x][j-1] - Map[i-1][y] + Map[i-1][j-1];

}


int maxArea(){

    for(int i = 1; i<n; i++) Map[i][0] += Map[i-1][0];
    for(int i = 1; i<m; i++) Map[0][i] += Map[0][i-1];
    for(int i = 1; i<n; i++)
        for(int j = 1; j<m; j++) Map[i][j] += Map[i-1][j] + Map[i][j-1] - Map[i-1][j-1];

    long long max = INT_MIN;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            for(int x = i; x<n; x++)
                for(int y = j; y<m; y++)
                    max = std::max(max, rangeSum(i, j, x, y));

    return max;

}



int main(){

    ios::sync_with_stdio(false);
    cin>>n>>m;
    while(n&&m){

        Map.assign(n, {});
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){

                cin>>k;
                Map[i].push_back((k)? INT_MIN: 1);

            }

        cout<<max(0, maxArea())<<'\n';
        cin>>n>>m;

    }return 0;


}
