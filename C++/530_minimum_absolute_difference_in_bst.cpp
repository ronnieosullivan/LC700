class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p = root, *pre = nullptr;
        int res = INT_MAX;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if (pre) res = min(res, p->val - pre->val);
            pre = p;
            p = p->right;
        }
        return res;
    }
};