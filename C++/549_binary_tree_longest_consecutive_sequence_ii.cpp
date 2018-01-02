class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root, root, res);
        return res;
    }
    pair<int, int> helper(TreeNode* node, TreeNode* parent, int& res) {
        if (!node) return {0, 0};
        auto left = helper(node->left, node, res);
        auto right = helper(node->right, node, res);
        res = max(res, left.first + right.second + 1);
        res = max(res, left.second + right.first + 1);
        int inc = 0, dec = 0;
        if (node->val == parent->val + 1) {
            inc = max(left.first, right.first) + 1;
        } else if (node->val + 1 == parent->val) {
            dec = max(left.second, right.second) + 1;
        }
        return {inc, dec};
    }
};