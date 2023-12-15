```cpp
int HouseRobberIII(unordered_map<string, int> &memo, TreeNode * root, long long unsigned i = 1, bool canRob = true){

    if(!root) return 0;

    string key = to_string(canRob) + " " + to_string(i);

    if(memo[key]) return memo[key];

    if(!canRob) return memo[key] = HouseRobberIII(memo, root->left, 2*i, true) + HouseRobberIII(memo, root->right, 2*i+1, true);

    return memo[key] = max(root->val + HouseRobberIII(memo, root->left, 2*i, false) +  HouseRobberIII(memo, root->right, 2*i+1, false), 
    HouseRobberIII(memo, root->left, 2*i, true) + HouseRobberIII(memo, root->right, 2*i+1, true));

    
}




class Solution {
public:
    int rob(TreeNode* root) {

        unordered_map<string, int> memo;
        return HouseRobberIII(memo, root);
        
        
    }
};
