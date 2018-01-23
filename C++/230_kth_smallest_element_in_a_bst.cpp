// Solution 1:
// in order, iterative

// Solution 2:
// in order, recursive
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    int dfs(TreeNode* root, int& k) {
        if (!root) return -1;
        int val = dfs(root->left, k);
        cout << k << endl;
        if (k == 0) return val;
        if (--k == 0) return root->val;
        return dfs(root->right, k);
    }
};

// Follow up:
class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode *left;
        MyTreeNode *right;
        MyTreeNode(int x) : val(x), count(1), left(NULL), right(NULL) {}
    };
    
    MyTreeNode* build(TreeNode* root) {
        if (!root) return NULL;
        MyTreeNode *node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);
        if (node->left) node->count += node->left->count;
        if (node->right) node->count += node->right->count;
        return node;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        MyTreeNode *node = build(root);
        return helper(node, k);
    }
    
    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            } else if (k > cnt + 1) {
                return helper(node->right, k - 1 - cnt);
            }
            return node->val;
        } else {
            if (k == 1) return node->val;
            return helper(node->right, k - 1);
        }
    }
};