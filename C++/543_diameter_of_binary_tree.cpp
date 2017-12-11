class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    // return depth
    int helper(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};