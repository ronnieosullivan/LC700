// Solution 1:
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* p = root;
        while (p) {
            s.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = s.top();
        s.pop();
        int res = p->val;
        if (p->right) {
            p = p->right;
            while (p) {
                s.push(p);
                p = p->left;
            }
        }
        return res;
    }
private:
    stack<TreeNode*> s;
};
