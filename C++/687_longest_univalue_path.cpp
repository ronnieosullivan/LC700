class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        left = (root->left && root->left->val == root->val) ? left + 1 : 0;
        right = (root->right && root->right->val == root->val) ? right + 1 : 0;
        res = max(res, left + right);
        return max(left, right);
    }
};