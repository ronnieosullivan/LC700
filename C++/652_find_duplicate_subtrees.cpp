class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m;
        helper(root, m, res);
        return res;
    }
    string helper(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res) {
        if (!node) return "# ";
        string str = to_string(node->val) + " " + helper(node->left, m, res)
            + " " + helper(node->right, m, res);
        m[str]++;
        if (m[str] == 2) res.push_back(node);
        return str;
    }
};