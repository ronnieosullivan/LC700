// Solution 1:
// since it is BST (preferred)
// same as upper_bound: it finds the first element that is > p->val
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return nullptr;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode *left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

// Solution 2:
// since it is BST (preferred)
// same as upper_bound: it finds the first element that is > p->val
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *res = nullptr;
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else root = root->right;
        }
        return res;
    }
};

// Solution 3:
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        stack<TreeNode*> s;
        TreeNode* it = root;
        while (it || !s.empty()) {
            while (it) {
                s.push(it);
                it = it->left;
            }
            it = s.top(); s.pop();
            if (it == p) found = true;
            else if (found) return it;
            it = it->right;
        }
        return nullptr;
    }
};

// Solution 4:
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        return helper(root, p, found);
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, bool& found) {
        if (!root) return nullptr;
        TreeNode* left = helper(root->left, p, found);
        if (left) return left;
        if (root == p) found = true;
        else if (found) return root;
        TreeNode* right = helper(root->right, p, found);
        return right;
    }
};