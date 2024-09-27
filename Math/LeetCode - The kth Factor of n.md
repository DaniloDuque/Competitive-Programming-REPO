```cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        int c = 1;
        vector<int> divs;
        while(c*c<n){
            if(!(n%c)) divs.push_back(c), divs.push_back(n/c);
            c++;
        }if(c*c==n) divs.push_back(c);
        sort(divs.begin(), divs.end());
        return (k-1 >= divs.size())? -1 : divs[k-1];
    }
};
