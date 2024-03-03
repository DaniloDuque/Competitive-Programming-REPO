```cpp
int dp[501][501];

class Solution {
public:
    int minDistance(string w1, string w2) {
        
        w1 = "_" + w1; w2 = "_" + w2;
        for(int i = 0; i < w1.size(); ++i) dp[i][0] = i;
        for(int i = 0; i < w2.size(); ++i) dp[0][i] = i;

        for(int i = 1; i < w1.size(); ++i)
            for(int j = 1; j < w2.size(); ++j)
                dp[i][j] = min(min(dp[i][j-1] + 1, dp[i-1][j] + 1), dp[i-1][j-1] + (w1[i] != w2[j]));
        
        return dp[w1.size()-1][w2.size()-1];

    }
};
