class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root) helper(root, "", res);
        return res;
    }
    void helper(TreeNode *node, string cur, vector<string> &res) {
        cur += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(cur);
        } else {
            if (node->left) helper(node->left, cur + "->", res);
            if (node->right) helper(node->right, cur + "->", res);
        }
    }
};