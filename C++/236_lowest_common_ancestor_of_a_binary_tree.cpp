class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        if (left && left != p && left != q) return left;
        TreeNode *right = lowestCommonAncestor(root->right, p , q);
        if (right && right != p && right != q) return right;
        if (left && right) return root;
        return left ? left : right;
    }
};