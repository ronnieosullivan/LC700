class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val, 0, res);
        return res;
    }
    void dfs(TreeNode *root, int v, int out, int &res) {
        if (!root) return;
        if (root->val == v + 1) ++out;
        else out = 1;
        res = max(res, out);
        dfs(root->left, root->val, out, res);
        dfs(root->right, root->val, out, res);
    }
};