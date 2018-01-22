// Solution 1:
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root);
        return max(res.first, res.second);
    }
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        pair<int, int> res;
        res.first = max(left.first, left.second) + max(right.first, right.second);
        res.second = left.first + right.first + root->val;
        return res;
    }
};