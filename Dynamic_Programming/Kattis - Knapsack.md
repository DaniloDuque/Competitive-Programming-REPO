```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> values, weights;
vector<vector<int>> memo;
vector<int> res;



void showItems(int cap, int item){

    if (cap == 0 || item <= 0) return;

    if (memo[cap][item] > memo[cap][item - 1]) {
        res.push_back(item - 1); 
        return showItems(cap - weights[item - 1], item - 1);
    }
   
    return showItems(cap, item - 1);
    
}




int Knapsack(int currCapacity, int item) {

    if (currCapacity < 0) return INT_MIN;

    if (!item || !currCapacity) return 0;

    if (memo[currCapacity][item]) return memo[currCapacity][item];

    return memo[currCapacity][item] = max(Knapsack(currCapacity, item - 1), values[item - 1] + Knapsack(currCapacity - weights[item - 1], item - 1));


}




int main() {

    std::ios::sync_with_stdio(false);
    int c, n, v, w;

    while (cin >> c >> n) {
        
        res.clear();
        values.clear();
        weights.clear();
        memo.assign(c + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            cin >> v >> w;
            values.push_back(v);
            weights.push_back(w);
        }

        Knapsack(c, n);
        showItems(c, n);

        cout << res.size() << '\n';
        for (int i : res)
            cout << i << " ";
        cout << '\n';

    }

    return 0;
}
