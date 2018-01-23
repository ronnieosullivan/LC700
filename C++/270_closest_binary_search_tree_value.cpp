class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            if (abs(res - target) >= abs(root->val - target)) {
                res = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};