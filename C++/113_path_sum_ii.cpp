class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(root, cur, sum, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& cur, int sum, vector<vector<int>>& res) {
        if (!root) return;
        cur.push_back(root->val);
        if (sum == root->val && !root->left && !root->right) {
            res.push_back(cur);
        }
        dfs(root->left, cur, sum - root->val, res);
        dfs(root->right, cur, sum - root->val, res);
        cur.pop_back();
    }
};