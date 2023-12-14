```cpp
#define set set<string>


unordered_map<int, set> memo;



set GenerateParenthesis(int n){

    if(n < 1) return {};
    if(n == 1) return {"()"};

    if(memo.find(n) != memo.end()) return memo[n];

    set result;

    for(string s: GenerateParenthesis(n-1)) result.insert("(" + s + ")");
    
    int i = n-1, j = 1;

    while(j <= i){

        for(string s: GenerateParenthesis(i))
            for(string k: GenerateParenthesis(j)){
                result.insert(k+s);
                result.insert(s+k);

            }

            

        i--;
        j++;

    }memo[n] = result;
    return result;

}







class Solution {

public:
    vector<string> generateParenthesis(int n){

        set result = GenerateParenthesis(n);
        vector<string> res;
        for(string s: result) res.push_back(s);
        return res;

    }
    
};
