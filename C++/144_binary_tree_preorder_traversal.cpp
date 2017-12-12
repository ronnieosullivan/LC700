class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->right;
            }
        }
        return res;
    }
};