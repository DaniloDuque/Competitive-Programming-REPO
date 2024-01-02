```cpp
#include <bits/stdc++.h>
using namespace std;

int n, x;
string s;
vector<vector<int>> mat;
vector<string> input;



void largestSubmatrix(){

    mat.assign(input.size()+1, vector<int>(input[0].size()+1, 0));
    for(int i = 1; i<mat.size(); ++i)
        for(int j = 1; j<mat[0].size(); ++j)
            mat[i][j] = ((input[i-1][j-1] == '1')? 1: -625) + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];

    int max = 0;
    for(int i = 1; i<mat.size(); i++)
        for(int j = 1; j<mat[0].size(); j++)
            for(int k = i; k<mat.size(); k++)
                for(int w = j; w<mat[0].size(); w++)
                    max = std::max(max, mat[k][w] - mat[i-1][w] - mat[k][j-1] + mat[i-1][j-1]);

    cout<<max<<'\n';

}



int main(){

    ios::sync_with_stdio(false);
    cin>>n;
    cin.ignore();
    getline(cin, s);
    while(n--){

        input.clear();
        while(getline(cin, s) && s != "") input.push_back(s);
        largestSubmatrix();
        if(n) cout<<'\n';

    }return 0;

}
