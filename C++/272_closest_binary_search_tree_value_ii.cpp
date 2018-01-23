class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> pre, suc;
        while (root) {
            if (root->val <= target) {
                pre.push(root);
                root = root->right;
            } else {
                suc.push(root);
                root = root->left;
            }
        }
        while (k-- > 0) {
            if (suc.empty() || !pre.empty() && target - pre.top()->val < suc.top()->val - target) {
                res.push_back(pre.top()->val);
                getPredecessor(pre);
            } else {
                res.push_back(suc.top()->val);
                getSuccessor(suc);
            }
        }
        return res;
    }
    void getPredecessor(stack<TreeNode*> &pre) {
        TreeNode *t = pre.top(); pre.pop();
        if (t->left) {
            pre.push(t->left);
            while (pre.top()->right) pre.push(pre.top()->right);
        }
    }
    void getSuccessor(stack<TreeNode*> &suc) {
        TreeNode *t = suc.top(); suc.pop();
        if (t->right) {
            suc.push(t->right);
            while (suc.top()->left) suc.push(suc.top()->left);
        }
    }
};