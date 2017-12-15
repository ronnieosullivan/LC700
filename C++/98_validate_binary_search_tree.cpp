// Solution 1:
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return helper(root, pre);
    }
    bool helper(TreeNode* root, TreeNode*& pre) {
        if (!root) return true;
        bool left = helper(root->left, pre);
        if (!left) return false;
        if (pre && root->val <= pre->val) return false;
        pre = root;
        bool right = helper(root->right, pre);
        return right;
    }
};

// Solution 2:
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = nullptr;
        while (!s.empty() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (pre && p->val <= pre->val) return false;
            pre = p;
            p = p->right;
        }
        return true;
    }
};