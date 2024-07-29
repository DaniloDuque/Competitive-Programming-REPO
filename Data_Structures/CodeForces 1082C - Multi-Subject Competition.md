```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m, s, r;
vector<vector<int>> mat;

bool cmp(vector<int> &x, vector<int> &y){
    return x.size() > y.size();
}

void accumulate(vector<int> &row){
    for(int i = 1; i<row.size(); ++i) row[i] += row[i-1];
}

signed main(){

    scanf("%lld %lld", &n, &m);
    mat.assign(m, {});
    for(int i = 0; i<n; ++i){
        scanf("%lld %lld", &s, &r);
        mat[s-1].push_back(r);
    }

    for(auto &row : mat){
        sort(row.rbegin(), row.rend());
        accumulate(row);
    }

    sort(mat.begin(), mat.end(), cmp);
    int rslt = 0;    
    for(int i = 0; i<n; ++i){
        int sum = 0;
        for(int j = 0; j<mat.size() && i < mat[j].size(); ++j)
            sum += max(0LL, mat[j][i]);

        rslt = max(rslt, sum);
    }
        
    printf("%lld\n", rslt);
    return 0;

}
