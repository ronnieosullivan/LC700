class Solution {
public:
    int countNodes(TreeNode* root) {
        int left = 0, right = 0;
        TreeNode* pLeft = root, *pRight = root;
        while (pLeft) {
            ++left;
            pLeft = pLeft->left;
        }
        while (pRight) {
            ++right;
            pRight = pRight->right;
        }
        if (left == right) return pow(2, left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};